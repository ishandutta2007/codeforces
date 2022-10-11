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

ll n, k, s[maxn], ans[maxn];

ll get(ll x, ll y){
	ll a, b;
	cout << "and " << x << " " << y << "\n";
	cout.flush();
	cin >> a;
	cout << "or " << x << " " << y << "\n";
	cout.flush();
	cin >> b;
	return a + b;
	
}

int main(){
	fast_io;
	
	cin >> n >> k;
	for(ll i = 2; i <= n; i++){
		s[i] = get(1, i);
	}
	ans[1] = (s[2] + s[3] - get(2, 3)) / 2;
	for(ll i = 2; i <= n; i++){
		ans[i] = s[i] - ans[1];
	}
	sort(ans + 1, ans + 1 + n);
	cout << "finish " << ans[k] << "\n";
	cout.flush();
	
	return 0;
}