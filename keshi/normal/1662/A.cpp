//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
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
#define Sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int t, n, a[20];

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		fill(a, a + 20, -1);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> y >> x;
			a[x] = max(a[x], y);
		}
		bool ok = 1;
		int ans = 0;
		for(int i = 1; i <= 10; i++){
			if(a[i] == -1) ok = 0;
			ans += a[i];
		}
		if(ok) cout << ans << "\n";
		else cout << "MOREPROBLEMS\n";
	}
	
	
	return 0;
}