#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=r*10+c-48; c=getchar(); }
	return r*t;
}
#include<array>
#include<vector>
#define F first
#define S second
#define op std::pair<i64,i64>
#define ops std::vector<op>
#define st std::array<i64,4>
i64 jmp(i64 a,i64 b){ return b+b-a; }
ops rev(ops a)
{
	std::reverse(a.begin(),a.end());
	for(auto &i:a) i.F=jmp(i.F,i.S);
	return a;
}
#define sort(a) std::sort(a.begin(),a.end())
st a[2]; i64 t,T;
ops &operator+=(ops &a,op b){ a.push_back(b); return a; }
ops solve(st a)
{
	ops ans; sort(a);
//	for(auto i:a) printf("%I64d ",i);; putchar(10);
#define Jmp(x,y) ans+={x,y},x=jmp(x,y)
#define Jmpr(x,y) ans+={x,y},x=jmp(x,y),std::swap(x,y)
	while(1)
	{
		sort(a); if(a[3]-a[0]<=1) break;
		while(1)
		{
			fr(i,1,2)
			{
				if(jmp(a[0],a[i])<=a[3]&&jmp(a[0],jmp(a[0],a[i]))>=a[3]){ Jmp(a[0],a[i]); goto lable1; }
				if(jmp(a[3],a[i])>=a[0]&&jmp(a[3],jmp(a[3],a[i]))<=a[0]){ Jmp(a[3],a[i]); goto lable1; }
			}
			int p2=jmp(a[0],a[2])<=a[3],p1=jmp(a[0],a[1])<=a[3];
			if(p2){ if(p1){ Jmp(a[1],a[0]); Jmp(a[1],a[2]); } else{ Jmp(a[1],a[2]); Jmp(a[1],a[0]); } }
			else{ if(!p1){ Jmp(a[1],a[3]); Jmp(a[1],a[2]); } else{ Jmp(a[1],a[2]); Jmp(a[1],a[3]); } }
			std::swap(a[1],a[2]);
		}
		lable1:;
//		for(auto i:a) printf("%I64d ",i);; putchar(10);
	}
//	for(auto i:a) printf("%I64d ",i);; putchar(10);
	assert(a[0]!=a[3]);
	if(a[0]&1)
	{
		int k=0; while(a[k]&1){ Jmp(a[k],a[3]); k++; }
		sort(a);
	}
//	for(auto i:a) printf(" %I64d",i);; putchar(10);
	fr(i,1,20){ Jmp(a[3],a[1]); Jmp(a[3],a[2]); Jmp(a[2],a[0]); Jmp(a[2],a[3]); }
//	printf("%I64d %I64d\n",a[3]-a[0],a[2]-a[1]);
	fd(i,20,1)
	{
		while(a[3]!=a[0]&&jmp(a[3],a[0])>=0) Jmpr(a[3],a[0]);
		while(a[2]!=a[1]&&jmp(a[2],a[1])>=0) Jmpr(a[2],a[1]);
		while(a[3]!=a[0]&&a[0]<0) Jmpr(a[0],a[3]);
		while(a[2]!=a[1]&&a[1]<0) Jmpr(a[1],a[2]);
		Jmp(a[2],a[3]); Jmp(a[2],a[0]);
		Jmp(a[3],a[2]); Jmp(a[3],a[1]);
	}
	while(a[3]!=a[0]&&jmp(a[3],a[0])>=0) Jmpr(a[3],a[0]);
	while(a[2]!=a[1]&&jmp(a[2],a[1])>=0) Jmpr(a[2],a[1]);
	while(a[3]!=a[0]&&a[0]<0) Jmpr(a[0],a[3]);
	while(a[2]!=a[1]&&a[1]<0) Jmpr(a[1],a[2]);
//	for(auto i:a) printf(" %I64d",i);; putchar(10);
	ops Ans; for(auto i:ans) if(i.F!=i.S) Ans+=i;
	return Ans;
}
int main()
{
	fr(j,0,1) fr(i,0,3) a[j][i]=read();
	i64 g[2]={0,0};
	fr(j,0,1) fr(i,1,3) g[j]=std::__gcd(g[j],std::abs(a[j][i]-a[j][0]));
	if(g[0]==0&&g[1]==0)
	{
		printf("%d\n",a[0][0]==a[1][0]?0:-1);
		return 0;
	}
	if(g[0]!=g[1]){ printf("-1\n"); return 0; }
	t=g[0]; T=(a[0][0]%t+t)%t; if((a[0][0]%t+t)%t!=(a[1][0]%t+t)%t){ printf("-1\n"); return 0; }
	fr(j,0,1) fr(i,0,3) a[j][i]=(a[j][i]-T)/t;
	int c[2]={0,0}; 
	fr(j,0,1) fr(i,0,3) if(a[j][i]%2) c[j]++;
	if(c[0]!=c[1]){ printf("-1\n"); return 0; }
	ops A[2];
	fr(i,0,1) A[i]=solve(a[i]);
	A[1]=rev(A[1]); fr(o,0,1) for(auto &i:A[o]){ i.F=i.F*t+T; i.S=i.S*t+T; }
	printf("%d\n",A[0].size()+A[1].size());
	fr(i,0,1) for(auto j:A[i]) printf("%I64d %I64d\n",j.F,j.S);
	return 0;
}