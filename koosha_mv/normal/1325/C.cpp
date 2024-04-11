#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=3e5+9;
ll t,n,x,y,deg[N],deg2,edge[N][2],e=1e5+2,a[4],cnt=3,c;
vector<int> g[N];
int main(){
	cin>>n;
	f(i,1,n){
		Gett(x,y);
		edge[i][0]=x,edge[i][1]=y;
		g[x].pb(y);
		g[y].pb(x);
		deg[x]++,deg[y]++;
	}
	f(i,1,n+1){
		if(g[i].size()>2){
			a[0]=i,a[1]=g[i][0],a[2]=g[i][1],a[3]=g[i][2];		
			break;
		}
	}
	sort(deg+1,deg+n+1);
	if(deg[n]==2 || n<3){
		f(i,0,n-1) cout<<i<<endl;
	}
	else{
		f(i,1,n){
			if((edge[i][0]==a[0])+(edge[i][0]==a[1])+(edge[i][0]==a[2])+(edge[i][0]==a[3])+(edge[i][1]==a[0])+(edge[i][1]==a[1])+(edge[i][1]==a[2])+(edge[i][1]==a[3])==2)
				cout<<c++<<endl;
			else
				cout<<cnt++<<endl;
		}
	}
}