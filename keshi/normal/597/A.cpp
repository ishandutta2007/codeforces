#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define R first
#define L second

long double x, a, b;
ll ans;

int main(){
	fast_io;
	
	cin >> x >> a >> b;
	
	ans = floor(b / x) - ceil(a / x) + 1;
	
	cout << ans;
	
	return 0;
}