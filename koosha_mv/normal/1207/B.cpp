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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=60;
int n,m,t,x,a[N][N],mark[N][N];
vector<pair<int,int> > ans;
bool sek(int x,int y){
	return (a[x][y]==1 && a[x+1][y]==1 && a[x][y+1]==1 && a[x+1][y+1]==1);
}
void check(int x,int y){
	if(a[x][y]==0) return ;
	if(sek(x,y)){
		if(!mark[x][y]){
			mark[x][y]=1;
			ans.pb(mp(x,y));
		}
		return ;
	}
	if(sek(x-1,y)){
		if(!mark[x-1][y]){
			mark[x-1][y]=1;
			ans.pb(mp(x-1,y));
		}
		return ;
	}
	if(sek(x,y-1)){
		if(!mark[x][y-1]){
			mark[x][y-1]=1;
			ans.pb(mp(x,y-1));
		}
		return ;
	}
	if(sek(x-1,y-1)){
		if(!mark[x-1][y-1]){
			mark[x-1][y-1]=1;
			ans.pb(mp(x-1,y-1));
		}
		return ;
	}
	cout<<-1;
	exit(0);
}
int main(){
	cin>>n>>m;
	f(i,1,n+1)
		f(j,1,m+1)
			cin>>a[i][j];
	f(i,1,n+1)
		f(j,1,m+1)
			check(i,j);
	cout<<ans.size()<<endl;
	f(i,0,ans.size())
		cout<<ans[i].F<<" "<<ans[i].S<<endl;
}