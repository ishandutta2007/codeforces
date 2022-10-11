#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll t, n, x, ans[MAXN], r;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		for(ll i = MAXN ; i >= 2; i--){
			x = i * (i - 1) / 2;
			ans[i] = n / x;
			if(ans[i]){
				r = max(r, i);
			}
			n %= x;
		}
		for(ll i = r; i > 0; i--){
			for(ll j = 0; j < ans[i]; j++){
				cout << 1;
			}
			cout << 3;
		}
		cout << 7 << endl;
	}
	
	return 0;
}