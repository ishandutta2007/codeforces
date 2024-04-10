#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=1<<12;
int a[12][mn];
int mx[mn];
int sc[12][mn];
int dp[2][mn];
vector<int>g[mn];
int cyc(int v,int n){return (v<<1)&((1<<n)-1)|((v>>(n-1))&1);}
int main(){
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#else
		cin.tie(0);
		cin.sync_with_stdio(0);
	#endif
	int tc;
	cin>>tc;
	for(int i=0;i<mn;i++)for(int j=0;j<=i;j++)if((i&j)==j)g[i].push_back(j);
	while(tc--){
		memset(dp,0,sizeof(dp));
		memset(sc,0,sizeof(sc));
		memset(a,0,sizeof(a));
		int n,m;
		cin>>n>>m;
		memset(mx,0,sizeof(mx));
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j],mx[j]=max(a[i][j],mx[j]);
		vector<int>v(m);
		iota(v.begin(),v.end(),0);
		sort(v.begin(),v.end(),[](int a,int b){return mx[a]>mx[b];});
		v.resize(min(n,m));
		for(int i=0;i<v.size();i++){
			for(int j=0;j<1<<n;j++){
				for(int k=0;k<n;k++)if((j>>k)&1)sc[i][j]+=a[k][v[i]];
			}
		}
		cerr<<sc[0][(1<<n)-1]<<endl;
		for(int i=0;i<v.size();i++)for(int j=0;j<1<<n;j++)for(int k=cyc(j,n);k!=j;k=cyc(k,n))
			sc[i][j]=max(sc[i][j],sc[i][k]);
		for(int i=0;i<v.size();i++){
			for(int j=0;j<1<<n;j++){
				for(int k:g[j]){
					dp[1][j]=max(dp[1][j],dp[0][k]+sc[i][j-k]);
				}
			}
			memcpy(dp[0],dp[1],sizeof(dp[0]));
			memset(dp[1],0,sizeof(dp[1]));
		}
		printf("%d\n",dp[0][(1<<n)-1]);
	}
}