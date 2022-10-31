#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,a,b;
bool vis[505][505];
map<tuple<int,int,int,int> ,int>mp;
vector<pair<int,int> > d={{0,1},{0,-1},{-1,0},{1,0}};
struct sb{
	int x,y,w;
	bool operator<(const sb a)const{return w>a.w;}
};
int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>m>>n;
		for(i=0;i<=n;i++)for(j=0;j<=n;j++)vis[i][j]=0;
		mp.clear();
		for(i=1;i<=m;i++){
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			if(a>c)swap(a,c);
			if(b>d)swap(b,d);
			if(a==c) mp[{a-1,b,a,b}]++,mp[{a,b,a-1,b}]++;
			else mp[{a,b-1,a,b}]++,mp[{a,b,a,b-1}]++;
		}
		priority_queue<sb> q;
		q.push({n/2,n/2,0});
		while(!q.empty()){
			auto [x,y,w]=q.top();q.pop();
			if(vis[x][y])continue;
			vis[x][y]=1;vis[n-x][n-y]=1;
			if(!x||x==n||!y||y==n){cout<<m-w<<'\n';break;}
			for(auto [dx,dy]:d){
				a=x+dx;b=y+dy;
				if(vis[a][b])continue;
				q.push({a,b,w+mp[{x,y,x+dx,y+dy}]+mp[{n-x,n-y,n-x-dx,n-y-dy}]});
			}
		}
	}
}//