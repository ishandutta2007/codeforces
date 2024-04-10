#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it;
ll w1,w2,f[600500],vis[600500],res=1e18;
string s[600500];
pair<int,int> pos[600500];
vector<pair<int,int> >d={{0,1},{0,-1},{-1,0},{1,0}};

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>w1>>w2;
	s[0]=s[n+1]=string(m+2,'#');
	for(i=1;i<=n;i++){cin>>s[i];s[i]="#"+s[i]+"#";}
	vector<vector<ll> >id(n+2,vector<ll>(m+2,0));
	for(i=1;i<=n;i++)for(j=1;j<=m;j++){
		id[i][j]=++it;
		pos[it]={i,j};f[it]=1e18;
	}
	priority_queue<tuple<ll,int,int> >q;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(s[i][j]=='.')q.push({0,i,j});
	while(!q.empty()){
		auto [w,x,y]=q.top();q.pop();
		k=id[x][y]; w=-w;
		if(vis[k])continue;
		vis[k]=1;f[k]=w;
		for(auto [dx,dy]:d){
			dx+=x;dy+=y;
			if(s[dx][dy]=='D')dx--;
			else if(s[dx][dy]=='U')dx++;
			else if(s[dx][dy]=='R')dy--;
			else if(s[dx][dy]=='L')dy++;
			else continue;
			if(vis[id[dx][dy]])continue;
			if(dx!=x&&dy!=y)q.push({-(w+w1),dx,dy});
			else q.push({-(w+w2),dx,dy});
		}
	}
	for(i=1;i<=n;i++)for(j=1;j<=m;j++){
		if(j<m)res=min(res,f[id[i][j]]+f[id[i][j+1]]);
		if(i<n)res=min(res,f[id[i][j]]+f[id[i+1][j]]);
	}
	if(res>1e17)cout<<-1;else cout<<res;
}