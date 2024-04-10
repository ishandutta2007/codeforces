#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 3e5+10;
const ll mod = 1e9+7;
 
vector<int>g[mn];
 
pii query(vector<int>&v){
	if(v.size()==0) return {0,0x3f3f3f3f};
	cout << "? " << v.size();
	for(int x:v)cout << " " << x;
	cout << endl;
	pii ret;
	cin >> ret.first >> ret.second;
	if(ret.first==-1)exit(0);
	return ret;
}
 
void report(int a,int b){
	cout << "! " << a << " " << b << endl;
	string cor;
	cin >> cor;
	if(cor != "Correct") exit(0);
}
 
int dep[mn],par[mn];
void dfs(int x,int p){
	par[x]=p;
	for(int y:g[x])if(y!=p){
		dep[y]=dep[x]+1;
		dfs(y,x);
	}
}
 
pii qrange(int t,int n){
	vi v;
	for(int i=1;i<=n;i++)if(dep[i]>=t)v.push_back(i);
	return query(v);
}
 
void fnd(int x,int p,vi&v,int d){
	if(dep[x]==d)v.push_back(x);
	for(int y:g[x])if(y!=p){
		fnd(y,x,v,d);
	}
}
 
int main()
{
	// cin.tie(0);
	// cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)g[i].clear(),dep[i]=par[i]=0;
		for(int i=0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		vi v;
		for(int i=1;i<=n;i++)v.push_back(i);
		pii p = query(v);
		int rt=p.first, d=p.second;
		dep[rt]=0;
		dfs(rt,rt);
		int l=d/2,r=d+1;
		int a;
		while(l<r){
			int m=(l+r)/2;
			cerr<<m<<endl;
			p=qrange(m,n);
			if(p.second==d)l=m+1,a=p.first;
			else r=m;
		}
		l--;
		cerr<<l<<endl;
		int no=a;
		while(dep[no]>1)no=par[no];
		assert(dep[no]<=1&&no!=0);
		cerr << no << " " << d-l << endl;
		v.clear();
		fnd(rt,no,v,d-l);
		int b=query(v).first;
		report(a,b);
	}
}