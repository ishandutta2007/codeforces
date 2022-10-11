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

ll n, x, ans;
pll a[MAXN];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].L >> a[i].R;
	}
	
	sort(a, a + n);
	
	x = -1;
	
	for(ll i = 0; i < n; i++){
		if(a[i].L > x){
			x = a[i].R;
			ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}