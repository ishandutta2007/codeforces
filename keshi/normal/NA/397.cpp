#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 100;
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

ll n;

int main(){
	fast_io;
	
	cin >> n;
	
	if(n % 2 == 0){
		cout << "NO";
		return 0;
	}
	
	cout << "YES" << endl;
	cout << 4 * n - 2 << " " << n * (2 * n - 1) << endl;
	
	for(ll i = 1; i < n; i++){
		for(ll j = n; j < 2 * n - 1; j++){
			cout << i << " " << j << endl;
		}
	}
	
	for(ll i = 1; i < n; i += 2){
		cout << i << " " << i + 1 << endl;
	}
	
	for(ll i = n; i < 2 * n - 1; i++){
		cout << i << " " << 2 * n - 1 << endl;
	}
	
	for(ll i = 3 * n; i < 4 * n - 1; i++){
		for(ll j = 2 * n + 1; j < 3 * n; j++){
			cout << i << " " << j << endl;
		}
	}
	
	for(ll i = 3 * n; i < 4 * n - 1; i += 2){
		cout << i << " " << i + 1 << endl;
	}
	
	for(ll i = 2 * n + 1; i < 3 * n; i++){
		cout << i << " " << 2 * n << endl;
	}
	
	cout << 2 * n - 1 << " " << 2 * n << endl;
	
	
	return 0;
}