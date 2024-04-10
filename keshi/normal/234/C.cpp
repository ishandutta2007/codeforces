#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, ans, a[MAXN], l[MAXN], r[MAXN];

int main(){
	fast_io;
	file_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		l[i] = l[i - 1];
		if(a[i] >= 0){
			l[i]++;
		}
	}
	
	for(ll i = n; i > 0; i--){
		r[i] = r[i + 1];
		if(a[i] <= 0){
			r[i]++;
		}
	}
	
	ans = INF;
	
	for(ll i = 1; i < n; i++){
		ans = min(ans, l[i] + r[i + 1]);
	}
	
	cout << ans;
	
	return 0;
}