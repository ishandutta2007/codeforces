#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=(r<<3)+(r<<1)+(c^48); c=getchar(); }
	return r*t;
}
#define pii std::pair<i64,i64>
#define F first
#define S second
const int N=800010; const i64 inf=1ll<<40;
int n,m;
i64 a[N];
std::vector<pii> g[N];
std::vector<i64> t[N];
i64 F[N][2][2],f[N][2];
i64 b[N],c;
i64 s[N],S;
inline void Min(i64 &a,i64 b){ if(a>b) a=b; }
int main()
{
	fr(T,1,read())
	{
		n=read(); m=read();
		fr(i,1,n) a[i]=read();
		fr(i,1,n+1) g[i].clear();
		std::sort(a+1,a+n+1); a[0]=-inf; a[n+1]=inf;
		fr(i,1,m)
		{
			i64 l=read(),r=read();
			int L=std::lower_bound(a+1,a+n+1,l)-a,R=std::upper_bound(a+1,a+n+1,r)-a;
			if(L!=R) continue;
			g[L].push_back({l,r});
		}
		fr(p,1,n+1) if(!g[p].empty())
		{
			c=0; int _n=g[p].size();
			for(auto i:g[p]){ b[++c]=i.F; b[++c]=i.S; }
			std::sort(b+1,b+c+1); c=std::unique(b+1,b+c+1)-b-1;
			b[0]=a[p-1]; b[c+1]=a[p];
			for(auto &i:g[p]){ i.F=std::lower_bound(b+1,b+c+1,i.F)-b; i.S=std::lower_bound(b+1,b+c+1,i.S)-b; }
			fr(i,1,c) t[i].clear();
			fr(i,0,_n-1){ t[g[p][i].F].push_back(i); t[g[p][i].S].push_back(i); }
			fr(i,0,_n-1) s[i]=2;
			S=0;
			int i=0,j=1; F[p][0][0]=F[p][0][1]=F[p][1][0]=F[p][1][1]=inf;
			while(1)
			{
				if(!S)
				{
					fr(x,0,1) fr(y,0,1) Min(F[p][x][y],(b[i]-b[0])*(x+1)+(b[c+1]-b[j])*(y+1));
					if(j==c+1) break;
					for(auto k:t[j]){ s[k]--; if(!s[k]) S++; }
					j++;
				}
				else
				{
					i++; for(auto k:t[i]){ if(!s[k]) S--; s[k]++; }
				}
			}
		}
		else F[p][0][0]=F[p][0][1]=F[p][1][0]=F[p][1][1]=0;
		fr(i,0,n+1) f[i][0]=f[i][1]=inf;
		f[0][0]=f[0][1]=0;
		fr(i,1,n+1) fr(j,0,1) fr(k,0,1) Min(f[i][k],f[i-1][j]+F[i][j^1][k]);
		printf("%I64d\n",std::min(f[n+1][0],f[n+1][1]));
	}
	return 0;
}