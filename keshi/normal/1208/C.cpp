// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 100;
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

ll n;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n / 2; i++){
		for(ll j = 0; j < n; j++){
			cout << (i * n + j) * 2 << " ";
		}
		cout << endl;
	}
	
	for(ll i = 0; i < n / 2; i++){
		for(ll j = 0; j < n; j++){
			cout << (i * n + j) * 2 + 1 << " ";
		}
		cout << endl;
	}
	
	return 0;
}