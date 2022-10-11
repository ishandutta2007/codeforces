#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
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

ll n, a[MAXN], x, f, e, r;

int main(){
	fast_io;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	x = a[n - 1] - a[0];
	e = 0;
	while(a[e] == a[0]){
		e++;
	}
	r = n - 1;
	while(a[r] == a[n - 1]){
		r--;
	}
	f = e * (n - r - 1);
	if(a[0] == a[n - 1]){
		f = e * (e - 1) / 2;
	}
	cout << x << " " << f;
	return 0;
}