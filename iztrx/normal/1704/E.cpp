#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
#define IOS ios::sync_with_stdio(0)
#define N 100005
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
void py(){cout<<"Yes\n";}
void pn(){cout<<"No\n";}
ll dp[N],val[N];
int T,n,m,i,j,deg[N],a[N],mn,mx,l[N],k,fl,x,y,ans;
vector<int>son[N],S[N];
bool qwq(){
	for(i=1;i<=n;++i){
		if(a[i])return 1;
	}
	return 0;
}
void solve(){
	vector<int>t;
	for(int i=1;i<=n;++i){
		if(a[i]>0)t.push_back(i);
	}
	for(int x,i=0;i<t.size();++i){
		x=t[i];--a[x];
		for(j=0;j<son[x].size();++j){
			++a[son[x][j]];
		}
	}
}
int solve_(){
	queue<int>q;
	vector<int>sx;
	for(int i=1;i<=n;++i){
		if(!deg[i])q.push(i);
	}
	while(q.size()){
		x=q.front();sx.push_back(x);q.pop();
//		cout<<x<<"\n";
		for(int i=0;i<S[x].size();++i){
			if(!(--deg[S[x][i]])){
				q.push(S[x][i]);
			}
		}
	}
//	for(int i=0;i<sx.size();++i)cout<<sx[i]<<" ";
	dp[sx[0]]=1;
	for(int i=1;i<n;++i){
		dp[sx[i]]=0;
		for(int j=0;j<son[sx[i]].size();++j)
			(dp[sx[i]]+=dp[son[sx[i]][j]])%=mod;
	}
	ll res=0;
	for(int i=1;i<=n;++i){
//		cout<<dp[i]<<" "<<a[i]<<"\n";
		(res+=dp[i]*a[i])%=mod;
	}
	return res;
}
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n>>m;ans=0;
		for(i=1;i<=n;++i)cin>>a[i],deg[i]=0,son[i].clear(),S[i].clear();
		for(i=1;i<=m;++i)cin>>x>>y,++deg[x],S[y].push_back(x),son[x].push_back(y);
		while(qwq()&&ans<=n){
			solve();++ans;
		}
//		if(ans>n)continue;
		if(qwq()){
			cout<<(ans+solve_())%mod<<"\n";
		}
		else cout<<ans<<"\n"; 
	}
}