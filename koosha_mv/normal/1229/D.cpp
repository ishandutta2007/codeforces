#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99,K=5,Mx=1e9,M=150;

int n,k,Time,a[N],mark[N],p[N],g[M][M];
vector<int> v,nimp,imp;
ll ans;
map<vector<int>,int> T;

vector<int> G(vector<int> s,vector<int> t){
	vector<int> ans(k);
	f(i,0,k){
		Time++;
		ans[t[i]]=s[i];
	}
	return ans;
}
void build(){
	vector<vector<int> > P;
	vector<int> v(k);
	f(i,0,k) v[i]=i;
	do{
		T[v]=P.size();
		P.pb(v);
	}while(next_permutation(v.begin(),v.end()));
	f(i,0,P.size()){
		f(j,0,P.size()){
			g[i][j]=T[G(P[i],P[j])];
			//cout<<i<<" "<<j<<" : "<<g[i][j]<<endl;
		}
	}
}
void reset(){
	vector<int> e;
	f(i,0,k) e.pb(i);
	f(i,0,v.size())
		mark[v[i]]=0;
	v.clear();
	nimp.clear();
	v.pb(T[e]);
	mark[T[e]]=1;
}
void Add(int x){
	if(mark[p[x]]) return ;
	nimp.pb(x);
	int sz=v.size();
	f(i,0,sz){
		int e=g[v[i]][p[x]];
		if(!mark[e]){
			v.pb(e);
			mark[e]=1;
		}
	}
	f(i,sz,v.size()){
		f(j,0,nimp.size()){
			int e=g[v[i]][p[nimp[j]]];
			if(!mark[e]){
				v.pb(e);
				mark[e]=1;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	build();
	f(i,1,n+1){
		vector<int> v;
		f(j,0,k){
			int x;
			cin>>x;
			v.pb(--x);
		}
		p[i]=T[v];
	}
	f_(i,n,1){
		reset();
		if(imp.size()>k){
			eror(imp.size());
		}
		Add(i);
		if(!imp.size()) ans+=v.size()*(n+1-i);
		else ans+=v.size()*(imp[0]-i);
		f(j,0,imp.size()){
			int nxt=(j==imp.size()-1 ? n+1 : imp[j+1]);
			Add(imp[j]);
			ans+=v.size()*(nxt-imp[j]);
		}
		imp=nimp;
		if(Time>Mx) eror(i);
	}
	cout<<ans;
}
/*
3 4
2 1 3 4
1 3 2 4
1 2 4 3
*/