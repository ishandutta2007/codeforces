#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector
#define all(x) (x).begin(), (x).end()
#define sz(w) (ll) w.size()
#define inf 9223372036854775807
#define mod 998244353
// #define endl '\n'
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);
ll nxt() {ll x; cin >> x; return x;}
vec<string>ar;
vec<vec<bool>>vis;
ll cnt;
void dfs(ll y, ll x, ll py, ll px){
	if(y<0||y>=sz(ar)||x<0||x>=sz(ar[0]))return;
	if(ar[y][x]=='.'||vis[y][x])return;
	vis[y][x]=true;
	dfs(y+1,x,py,px);
	dfs(y-1,x,py,px);
	dfs(y,x+1,py,px);
	dfs(y,x-1,py,px);
	// cout<<y<<" "<<py<<" "<<x<<" "<<px<<endl;
	if(py==y&&px==x)++cnt;
}

void solve(ll test_number){
	ll n=nxt(),m=nxt();
	ar.resize(n);
	vis.resize(n,vec<bool>(m));	
	for(ll i=0;i<n;++i)
		cin>>ar[i];
	vec<bool>ish(n);
	vec<bool>isw(m);
	ll cnth=0,cntw=0;
	for(ll i=0;i<n;++i){
		for(ll j=0;j<m;++j){
			if(!ish[i]&&ar[i][j]=='#'){
				++cnth;
				ish[i]=true;
			}
			if(!isw[j]&&ar[i][j]=='#'){
				++cntw;
				isw[j]=true;
			}
		}
	}
	if((cnth==n)^(cntw==m)){
		cout<<-1<<endl;
		return;
	}
	for(ll i=0;i<n;++i){
		bool ac=false,ac2=false;
		for(ll j=0;j<m;++j){
			if(ar[i][j]=='#'&&!ac)ac=true;
			if(ar[i][j]=='.'&&ac)ac2=true;
			if(ar[i][j]=='#'&&ac&&ac2){
				cout<<-1<<endl;
				return;
			}
		}		
	}
	for(ll i=0;i<m;++i){
		bool ac=false,ac2=false;
		for(ll j=0;j<n;++j){
			if(ar[j][i]=='#'&&!ac)ac=true;
			if(ar[j][i]=='.'&&ac)ac2=true;
			if(ar[j][i]=='#'&&ac&&ac2){
				cout<<-1<<endl;
				return;
			}
		}
	}
	for(ll i=0;i<n;++i)
		for(ll j=0;j<m;++j)
			dfs(i,j,i,j);
	cout<<cnt<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	ll t = 1;
	// cin >> t;
	for (ll i = 0; i < t; ++i){ 
		solve(i);
	}
}