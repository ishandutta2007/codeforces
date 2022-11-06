#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace io{
	const int l=1<<20;
	char buf[l],*s,*t;
	inline char gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,l,stdin);
			return s==t?EOF:*s++;
		}
		return *s++;
	}
	char c;bool f;
	template<class IT>inline void gi(IT &x){
		x=0;f=0;c=gc();while(c<'0'||c>'9'){if(c=='-')f=1;c=gc();}
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^'0');c=gc();}if(f)x=-x;
	}
};
using io::gi;
struct qwq{
	int a,b,c;
	inline qwq(){}
	inline qwq(int a,int b,int c):a(a),b(b),c(c){}
	inline bool operator<(const qwq &x)const{
		return c<x.c;
	}
};
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}
template<class IT>inline void cmax(IT &a,IT b){if(a<b)a=b;}
const int N=1000005,inf=1000000007;
qwq x[N<<1];
ll ans[N];int a[N];
priority_queue<int>q1,q2;
inline int que(){
	while(!q2.empty()&&q1.top()==q2.top()){q1.pop();q2.pop();}
	return q1.top();
}
int main(){
	int q,n,m,t,tot,i,j;
	gi(q);gi(n);
	while(q--){
		gi(m);t=n-m+1;
		for(i=1;i<=m;++i)gi(a[i]);
		tot=3;
		x[1]=qwq(1,0,  1);
		x[2]=qwq(0,0,t  );
		x[3]=qwq(1,0,m+1);
		for(i=1;i<=m;++i){
			x[++tot]=qwq(1,a[i],i  );
			x[++tot]=qwq(0,a[i],i+t);
		}
		sort(x+1,x+tot+1);
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
//		printf("\n\n\nm=%d t=%d tot=%d\n",m,t,tot);
		for(i=j=1;i<=tot&&x[i].c<=n;i=j){
			while(x[i].c==x[j].c){
//				printf("i=%d j=%d x[j]=(%d,%d,%d)\n",i,j,x[j].a,x[j].b,x[j].c);
				if(x[j].a)q1.push(x[j].b);
				else      q2.push(x[j].b);
				++j;
			}
//			printf("End max=%d\n",*(--S.end()));
			ans[x[i].c]+=que();
			ans[x[j].c]-=que();
		}
	}
	for(i=1;i<=n;++i)printf("%I64d ",ans[i]+=ans[i-1]);
	return 0;
}