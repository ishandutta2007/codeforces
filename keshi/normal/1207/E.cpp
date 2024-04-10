// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
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


ll a, b, e, ans;

int main(){
	fast_io;
	
	cout << "? ";
	for(ll i = 0; i < 100; i++){
		cout << i << " ";
	}
	fflush(stdout);
	cout << endl;
	
	cin >> a;
	
	cout << "? ";
	for(ll i = 1; i < 101; i++){
		cout << i * 128 << " ";
	}
	fflush(stdout);
	cout << endl;
	
	cin >> b;
	e = 1;
	for(ll i = 0; i < 7; i++){
		ans += (b % 2) * e;
		b /= 2;
		a /= 2;
		e *= 2;
	}
	
	for(ll i = 0; i < 7; i++){
		ans += (a % 2) * e;
		a /= 2;
		e *= 2;
	}
	
	cout << "! " << ans;
	
	return 0;
}