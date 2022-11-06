#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300100;
int p[N],mypos[N],vis[N];
int n,m;

int dfs(int u){
	if(vis[u])return 0;
	vis[u]=true;
	return dfs(mypos[p[u]])+1;
}

bool tr(int sh){
	for(int i=0;i<n;++i)mypos[i]=(i+sh)%n;
	memset(vis,0,sizeof(*vis)*n);
	int need=0;
	for(int i=0;i<n;++i)if(!vis[i])need+=dfs(i)-1;
	return need<=m;
}

void ProGamerMove(){
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>p[i],--p[i];
	vector<int>hist(n);
	for(int i=0;i<n;++i)if(p[i]<=i)++hist[i-p[i]];
	else ++hist[n-(p[i]-i)];
	vector<int>res;
	for(int i=0;i<n;++i)if(hist[i]>=n-2*m&&tr(i))res.push_back(i);
	cout<<res.size()<<" ";
	for(int&v:res)cout<<v<<" ";cout<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}