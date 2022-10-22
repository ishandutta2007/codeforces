#include <bits/stdc++.h>

#define fileopen(a, b) freopen(((std::string)a + ".inp").c_str(), "r", stdin); freopen(((std::string)b + ".out").c_str(), "w", stdout);
#define fileopen1(a) freopen(((std::string)a + ".inp").c_str(), "r", stdin); freopen(((std::string)a + ".out").c_str(), "w", stdout);

using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
ll const mod = 1e9 + 7, MAXN = 2e5 + 5,oo = 3e18;

ll tc,n,m;

bool comp1 (string a,string b){
	ll mi = min(a.size(),b.size());
	for (int i = 1 ; i <= mi ; i++){
		char aa = a[i - 1],bb = b[i - 1];
		if (i % 2 == 1){
			if (aa < bb){
				return true;
			}
			else if (aa > bb){
				return false;
			}
		}
		else {
			if (aa > bb){
				return true;
			}
			else if (aa < bb){
				return false;
			}
		}
	}
	return true;
}

bool comp(pair<string,ll> a,pair<string,ll> b){
	return comp1(a.fi,b.fi);
}

vector<pair<string,ll>> vi;
void caau(){
	// calm
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		string cur; cin >> cur;
		vi.pb(mp(cur,i));
	}
	sort(vi.begin(),vi.end(),comp);
	for (auto cur : vi){
		cout << cur.se << " ";
	}
}

signed main() {
#ifdef thisiscaau
	fileopen("input", "output");
#endif
#ifndef thisiscaau
	// fileopen1("LAH");
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	tc = 1;
	while (tc--) caau();
}