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
const int N=105;
int n,t,m,k,ans[N*N],mark[N*N],an=1e9;
string s[N];
void bfs(queue<int> q){
	while(q.size()){
		int u=q.front();
		q.pop();
		if(mark[(u+1)%m]==-1)
			mark[(u+1)%m]=mark[u]+1,q.push((u+1)%m);
		if(mark[(u+m-1)%m]==-1)
			mark[(u+m-1)%m]=mark[u]+1,q.push((u+m-1)%m);
	}
}
void solve(string s1){
	f(i,0,m) mark[i]=-1;
	queue<int> q;
	f(i,0,m)
		if(s1[i]=='1')
			q.push(i),mark[i]=0;
	bfs(q);
	f(i,0,m) ans[i]+=mark[i];
}
int main(){
	cin>>n>>m;
	f(i,0,n){
		cin>>s[i];
		k=0;
		f(j,0,m)
			k+=(s[i][j]=='1');
		if(k==0) return cout<<-1,0;
		solve(s[i]);
	}
	f(i,0,m) minm(an,ans[i]);
	cout<<an;
}