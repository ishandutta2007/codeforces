#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=4e3+9;
int n,sz;
bool vis[19];
char s[M];
int q[M<<1],val[M],c[M][12],f[M],dp[M][M<<1];
vector<int>p[M][M<<1];
void get_fail(){
	queue<int>q;
	for(int j=0;j<12;++j)if(c[0][j]){
		q.push(c[0][j]);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int j=0;j<12;++j){
			int &v=c[u][j];
			if(!v){
				v=c[f[u]][j];
			}
			else {
				f[v]=c[f[u]][j];
				val[v]+=val[f[v]];
				q.push(v);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<M<<1;++i)q[i]=-1;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x>>(s+1);
		int m=strlen(s+1);
		for(int j=0;j<='l'-'a';++j)vis[j]=0;
		int l=M,r=M,now=M;
		q[l]=s[1]-'a';
		bool bol=0;
		vis[s[1]-'a']=1;
		for(int j=2;j<=m;++j){
			int o=s[j]-'a';
			if(vis[o]){
				if(q[now-1]!=o&&q[now+1]!=o){

					bol=1;
					break;
				}
				if(q[now-1]==o)now--;
				else now++;
			}
			else{
				vis[o]=1;
				if(now!=r&&now!=l){
					bol=1;
					break;
				}
				if(now==r){
					q[now=++r]=o;
				}
				else q[now=--l]=o;
			}
		}
		if(bol)continue;
		for(int j=l,u=0;j<=r;++j){
			int o=q[j];
			if(!c[u][o])c[u][o]=++sz;
			u=c[u][o];
			if(j==r)val[u]+=x;
		}
		for(int j=r,u=0;j>=l;--j){
			int o=q[j];
			if(!c[u][o])c[u][o]=++sz;
			u=c[u][o];
			if(j==l)val[u]+=x;
		}
		for(int j=l;j<=r;++j)q[j]=-1;
	}
	get_fail();
	for(int i=0;i<=sz;++i){
		for(int j=0;j<1<<12;++j)dp[i][j]=-1e9;
	}
	dp[0][0]=0;
	queue<pii>q;
	q.push(make_pair(0,0));
	int ans=0;
	while(!q.empty()){
		auto o=q.front();
		q.pop();
		int u=o.fi;
		if(o.se==(1<<12)-1)ans=max(ans,dp[u][o.se]);
		for(int j=0;j<12;++j){
			if(o.se>>j&1)continue;
			int v=c[u][j];
			if(dp[v][o.se|1<<j]==-1e9)q.push(make_pair(v,o.se|1<<j));
			if(dp[v][o.se|1<<j]<dp[u][o.se]+val[v]){
				p[v][o.se|1<<j]={u,o.se,j};
				dp[v][o.se|1<<j]=max(dp[v][o.se|1<<j],dp[u][o.se]+val[v]);
			}
		}
	}
	vector<int>sum;
	for(int i=0;i<=sz;++i){
		if(dp[i][(1<<12)-1]==ans){
			int x=i,y=(1<<12)-1;
			while(y){
				int nx=p[x][y][0];
				int ny=p[x][y][1];
				sum.eb(p[x][y][2]);
				x=nx;
				y=ny;
			}
			break;
		}
	}
	reverse(sum.begin(),sum.end());
	for(auto o:sum)cout<<char(o+'a');
	cout<<"\n";
	return 0;
}
/*
2
7 ab
6 ab



1000000000
0010000000
0010000000
0000001000
0001000000
0100000000
0000010000
0000000010
*/