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
const int N=2e6+9;
int n,c=1,ans=0,degsum,tv,k[3],edge[N][2],b[N],mark[N];
map<int,int> t,a;
vector<int> g[N];
void dfs(int x){
	mark[x]=1,tv++,degsum+=g[x].size();
	k[0]=a[x];
	sort(k,k+3);
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			dfs(g[x][i]);
}
int main(){
	cin>>n;
	f(i,0,n){
		Gett(edge[i][0],edge[i][1]);
		b[i*2]=edge[i][0],b[i*2+1]=edge[i][1];
	}
	sort(b,b+n+n);
	f(i,0,n*2){
		if(i==0 || b[i]!=b[i-1])
			a[c]=b[i],t[b[i]]=c++;
	}
	f(i,0,n){
		g[t[edge[i][0]]].pb(t[edge[i][1]]);
		g[t[edge[i][1]]].pb(t[edge[i][0]]);
	}
	f(i,1,c){
		if(!mark[i]){
			degsum=0,tv=0;
			k[0]=k[1]=k[2]=0;
			dfs(i);
			degsum/=2;
			if(degsum>tv) return cout<<-1,0;
			maxm(ans,k[1]);
			if(degsum==tv)
				maxm(ans,k[2]);
		}
	}
	cout<<ans;
}