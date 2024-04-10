#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, k, a[MAXN], b[MAXN], ans, j;
string s;

int main(){
	fast_io;
	
	cin >> n >> k >> s;
	
	a[n + 1] = INF;
	b[n + 1] = INF;
	
	for(ll i = 0; i < n; i++){
		a[i + 1] = a[i];
		b[i + 1] = b[i];
		if(s[i] == 'a'){
			a[i + 1]++;
		}
		else{
			b[i + 1]++;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		j = upper_bound(a, a + n + 2, k + a[i - 1]) - a;
		ans = max(ans, j - i);
		j = upper_bound(b, b + n + 2, k + b[i - 1]) - b;
		ans = max(ans, j - i);
	}
	
	cout << ans;
	
	return 0;
}