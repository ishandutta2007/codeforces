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
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n;
vector<vector<ll> > vec;

int main(){
    fast_io;

	cin >> n;

	if(n == 5){
		cout << "6\n3 5 4 2\n3 3 1 5\n4 4 5 2 3\n4 4 3 2 1\n3 4 2 1\n3 3 1 5";
		return 0;
	}
	if(n & 1){
		vec.pb({3, n, n - 1, n - 2});
		vec.pb({3, n, n - 1, n - 2});
		for(ll i = 1; i < n - 2; i += 2){
			vec.pb({4, i, n, i + 1, n - 1});
			vec.pb({4, i, n - 1, i + 1, n - 2});
			vec.pb({4, i, n - 2, i + 1, n});
		}
		n -= 3;
	}
	while(n > 4){
		for(ll i = 1; i < n - 1; i += 2){
			vec.pb({4, i, n, i + 1, n - 1});
		}
		for(ll i = 3; i < n - 1; i += 2){
			vec.pb({4, i, n, i + 1, n - 1});
		}
		vec.pb({3, 1, n, n - 1});
		vec.pb({3, 2, n, n - 1});
		n -= 2;
	}
	if(n == 4){
		vec.pb({3, 1, 2, 3});
		vec.pb({3, 2, 3, 4});
		vec.pb({3, 3, 4, 1});
		vec.pb({3, 4, 1, 2});
	}
	cout << vec.size() << '\n';
	for(auto i : vec){
		for(ll j : i){
			cout << j << " ";
		}
		cout << '\n';
	}

    return 0;
}