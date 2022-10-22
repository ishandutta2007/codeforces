#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=2e5+9;

int n,m,x,y,c;
vector<int> ans;
set<int> s;
map<int,int> g[N];

void dfs(int x){
	queue<int> q;
	c=0;
	q.push(x);
	while(q.size()){
		int u=q.front();c++;
		q.pop();
		vector<int> o;
		for(auto v:s)
		    if(!g[u][v]){
		        q.push(v);
		        o.pb(v);
		    }
		f(i,0,o.size())
		    s.erase(o[i]);
	}
}

int main(){
	cin>>n>>m;
	f(i,0,m){
	    cin>>x>>y;
		g[x][y]=1;
		g[y][x]=1;
	}
	f(i,0,n)
		s.insert(i+1);
	while(s.size()){
		x=*s.begin();
		s.erase(x);
		dfs(x);
		ans.pb(c);
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	print(ans,ans.size());
}