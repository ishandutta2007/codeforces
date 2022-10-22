#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=505;
int n,m,t,x,y,b1,b2,dst[N],matris[N][N],mark[N];
vector<int> p1,p2,g[N];
string s;

void dfs(int x,int dist){
	dst[x]=dist;
	mark[x]=1;
	if(dist%2) p1.pb(x);
	else b2++,p2.pb(x);
	f(i,0,g[x].size())
		if(mark[g[x][i]]==1 && dst[g[x][i]]%2==dist%2){
			cout<<"NO";
			exit(0);
		}
	f(i,0,g[x].size())
		if(mark[g[x][i]]==0)
			dfs(g[x][i],dist+1);
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		Gett(x,y);
		matris[x][y]=matris[y][x]=1;
	}
	f(i,1,n+1)
		f(j,1,i)
			if(matris[i][j]==0)
				g[i].pb(j),g[j].pb(i);
	f(i,1,n+1){
		if(mark[i]==0){
			if(g[i].size()>0){
				t++;
				if(t>1) return cout<<"NO",0;
				dfs(i,0);
			}
		}
	}
	f(i,0,p1.size())
		if(g[p1[i]].size()<b2)
		  return cout<<"NO",0;
	cout<<"YES"<<endl;
	f(i,0,n)
		s+='p';
	f(i,0,p1.size())
		s[p1[i]-1]='a';
	f(i,0,p2.size())
		s[p2[i]-1]='c';
	f(i,0,n) if(s[i]=='p') s[i]='b';
	cout<<s;
}