#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
#define int long long
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=(r<<3)+(r<<1)+(c^48); c=getchar(); }
	return r*t;
}
#define pii std::pair<int,int>
#define F first
#define S second
const int N=1<<20|10;
i64 n,m,k;
i64 l[N],r[N]; i64 q[N];
i64 L,R;
std::map<pii,int> o;
std::vector<pii> D[N],rD[N];
void init()
{
	fd(i,n,1)
	{
		auto it=o.lower_bound({l[i],0});
		if(it!=o.begin())
		{
			it--;
			if(it->F.S>l[i])
			{
				auto It=*it; o.erase(it);
				o[{It.F.F,l[i]}]=o[{l[i],It.F.S}]=It.S;
			}
			it=o.lower_bound({l[i],0});
		}
		while(it!=o.end()&&it->F.F<r[i])
		{
			auto It=*it; it=o.erase(it);
			if(It.F.S>r[i]) o[{r[i],It.F.S}]=It.S;
			D[i].push_back({It.S,std::min(r[i],It.F.S)-It.F.F});
		}
		o[{l[i],r[i]}]=i;
//		for(auto j:o) printf("%d %d  %d\n",j.F.F,j.F.S,j.S);; putchar(10);
	}
	fr(i,1,n) for(auto j:D[i]) rD[j.F].push_back({i,j.S});
//	fr(i,1,n) for(auto j:D[i]) printf("%d %d %d\n",i,j.F,j.S);
}
i64 ans;
i64 solve(i64 p)
{
	i64 s=0; i64 Ans=0; ans=0;
	for(int i=n+1,j=n;i>=1;)
	{
		if(j>=i&&s>=p)
		{
			Ans+=s; s-=r[j]-l[j];
			for(auto k:rD[j]) if(i<=k.F) s+=k.S;
			j--;
		}
		else
		{
			q[i]=j+1; ans+=Ans; i--; s+=r[i]-l[i]; Ans+=(r[i]-l[i])*(n-j);
			for(auto k:D[i])
			{
				if(j>=k.F) s-=k.S;
				Ans-=k.S*std::min(n-j,n-k.F+1);
			}
		}
//		printf(" %d %d  %I64d  %I64d  %I64d\n",i,j,s,Ans,ans);
	}
//	printf("%I64d %I64d\n",p,ans);
//	fr(i,1,n) printf("%d%c",q[i],i==n?'\n':' ');
	i64 Q=0;
	fr(i,1,n) Q+=n-q[i]+1;
	return Q;
}
signed main()
{
	n=read(); k=read();
	fr(i,1,n){ l[i]=read(); r[i]=read(); }
	init();
	L=0; R=1000000000;
	while(L<R)
	{
		i64 mid=(L+R)>>1;
		if(solve(mid)<=k) R=mid;
		else L=mid+1;
	}
	solve(R); ans+=(R-1)*k;
	fd(i,n,1) ans-=(R-1)*(n-q[i]+1);
	printf("%I64d\n",ans);
	return 0;
}