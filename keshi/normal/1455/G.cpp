//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, cnt, p;
string t;
set<pll> a[maxn];
map<ll, ll> mp[maxn];
ll b[maxn];
vector<ll> vec;

int main(){
    fast_io;

	vec.pb(0);
	a[0].insert(Mp(0, 0));
	mp[0][0] = 0;
	cnt++;
	
	cin >> n >> p;
	for(ll i = 0; i < n; i++){
		cin >> t;
		if(t == "set"){
			ll x, y;
			cin >> x >> y;
			ll m = vec.back();
			if(x != p){
				ll z = a[m].begin()->F - y;
				if(mp[m].find(x) != mp[m].end()){
					a[m].erase(Mp(mp[m][x], x));
				}
				mp[m][x] = z;
				a[m].insert(Mp(z, x));
			}
			b[m] += y;
		}
		if(t == "if"){
			ll x;
			cin >> x;
			ll m = vec.back();
			ll z;
			if(mp[m].find(x) == mp[m].end()){
				z = inf;
			}
			else{
				z = mp[m][x] + b[m];
				a[m].erase(Mp(mp[m][x], x));
				mp[m].erase(x);
			}
			
			vec.pb(cnt);
			a[cnt].insert(Mp(z, x));
			mp[cnt][x] = z;
			cnt++;
		}
		if(t == "end"){
			ll m = vec.back();
			vec.pop_back();
			if(mp[m].size() > mp[vec.back()].size()) swap(m, vec.back());
			for(map<ll, ll>::iterator it = mp[m].begin(); it != mp[m].end(); it++){
				if(mp[vec.back()].find(it->F) == mp[vec.back()].end() || mp[vec.back()][it->F] + b[vec.back()] > it->S + b[m]){
					if(mp[vec.back()].find(it->F) != mp[vec.back()].end()){
						a[vec.back()].erase(Mp(mp[vec.back()][it->F], it->F));
					}
					ll z = it->S + b[m] - b[vec.back()];
					mp[vec.back()][it->F] = z;
					a[vec.back()].insert(Mp(z, it->F));
				}
			}
		}
	}
	cout << a[vec.back()].begin()->F + b[vec.back()];

    return 0;
}