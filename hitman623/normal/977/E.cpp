#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
  
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int n,m,leader[200005];
vector<int> adj[200005], groups[200005];

// DSU
int find_leader(int x){
	if(leader[x] == x) return x;
	else return leader[x] = find_leader(leader[x]);
}

void merge(int x,int y){
	int lx = find_leader(x);
	int ly = find_leader(y);
	if(lx == ly) return;
	leader[ly] = lx;
}

void solve(){
	cin>>n>>m;
	rep(i,1,n+1) leader[i] = i;
	rep(i,0,m){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
		merge(u,v);
	}
	for(int i=1;i<=n;i++){
		groups[find_leader(i)].pb(i);
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(leader[i] == i){
			// actual leader, hence a new connected component
			// nodes in component = groups[i]
			bool is_cycle = true;
			for(auto node:groups[i]){
				if(sz(adj[node]) != 2){
					is_cycle = false;
					break;
				}
			}
			if(is_cycle) ans++;
		}
	}
	cout<<ans<<endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}