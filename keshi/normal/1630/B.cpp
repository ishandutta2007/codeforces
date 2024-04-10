//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
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

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int t, n, k, a[maxn], c[maxn];

int check(int x){
	int y = 0;
	for(int i = 1; i <= x; i++){
		y += c[i];
	}
	for(int i = 1; i <= n; i++){
		y += c[i + x];
		if(y - (n - y) >= k) return i;
		y -= c[i];
	}
	return -1;
}

int main(){
	fast_io;

	cin >> t;
	while(t--){
		cin >> n >> k;
		fill(c, c + n + n + n + 10, 0);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			c[a[i]]++;
		}
		int l = -1, r = n + 10;
		while(r - l > 1){
			int mid = (l + r) >> 1;
			if(check(mid) != -1) r = mid;
			else l = mid;
		}
		int x = check(r);
		int y = x + r;
		cout << x << " " << y << "\n";
		int p = 1, cc = 0;
		for(int i = 0; i < n; i++){
			if(x <= a[i] && a[i] <= y) cc++;
			else cc--;
			if(cc > 0 && (k != 1 || i == n - 1)){
				cc = 0;
				cout << p << " " << i + 1 << "\n";
				p = i + 2;
				k--;
			}
		}
	}
	
	return 0;
}