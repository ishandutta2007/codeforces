#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2e4+9;
ll n,rt,x,y,c[N],sub[N],ans[N];
vector<int> g[N],h;
void su(int x){
	sub[x]=1;
	f(i,0,g[x].size()){
		su(g[x][i]);
		sub[x]+=sub[g[x][i]];
	}
}
void dfs(int x,vector<int> v){
	if(c[x]>=v.size()){
		cout<<"NO";
		exit(0);
	}
	ans[x]=v[c[x]];
	v.erase(v.begin()+c[x]);
	vector<int> v1;ll p1=0;
	f(i,0,g[x].size()){
		f(j,0,sub[g[x][i]]){
			v1.pb(v[p1]);
			p1++;
		}
		dfs(g[x][i],v1);
		v1.clear();
	}
}
int main(){
	cin>>n;
	f(i,1,n+1){
		cin>>x>>y;c[i]=y;
		if(x==0) rt=i;
		else g[x].pb(i);
	}
	su(rt);
	f(i,1,n+1) h.pb(i);
	dfs(rt,h);
	cout<<"YES"<<endl;
	f(i,1,n+1)
		cout<<ans[i]<<" ";
}