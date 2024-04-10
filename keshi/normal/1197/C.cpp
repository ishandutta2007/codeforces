#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a[MAXN], ans, b[MAXN];

int main(){
	fast_io;
	
	cin >> n >> k;
	cin >> a[0];
	for(ll i = 1; i < n; i++){
		cin >> a[i];
		b[i - 1] = a[i] - a[i - 1];
	}
	sort(b, b + n, greater<ll>());
	ans = a[n - 1] - a[0];
	for(int i = 0; i < k - 1; i++){
		ans -= b[i];
	}
	cout << ans;
	
	return 0;
}