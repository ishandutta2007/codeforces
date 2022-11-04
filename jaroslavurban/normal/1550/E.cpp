#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100,K=17;;
string s;
int lenl[K][N],nxt[K][N],dp[1<<K];
int n,k,p;

int getnxt(int u,int ck){return u>=N||lenl[ck][u]>=p?u:nxt[ck][u]=getnxt(nxt[ck][u],ck);}

int solvedp(int m){
	if(~dp[m])return dp[m];
	if(!m)return dp[m]=0;
	dp[m]=INT_MAX;
	for(int ck=0;ck<k;++ck)if(1<<ck&m){
		int nm=m^1<<ck;
		int npos=getnxt(solvedp(nm),ck);
		if(npos<n)dp[m]=min(dp[m],npos+p);
	}
//	cerr<<m<<" "<<dp[m]<<endl;
	return dp[m];
}

bool solve(){
	for(int ck=0;ck<k;++ck){
		iota(nxt[ck],nxt[ck]+N,1);
		for(int i=n-1;i>=0;--i)if(s[i]=='a'+ck||s[i]=='?')lenl[ck][i]=lenl[ck][i+1]+1;
		else lenl[ck][i]=0;
	}
	memset(dp,-1,sizeof(dp));
	return solvedp((1<<k)-1)<=n;
}

void ProGamerMove(){
	cin>>n>>k>>s;
//	p=3;
//	solve();
	int l=0,r=n+1;
	int res=0;
	while(l<r){
		int m=(l+r)/2;
		p=m;
		if(solve())res=max(res,m),l=m+1;
		else r=m;
	}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}