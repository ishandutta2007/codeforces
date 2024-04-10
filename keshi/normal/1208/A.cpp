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

ll t, a[10], n;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> a[0] >> a[1] >> n;
		a[2] = a[0] ^ a[1];
		cout << a[n % 3] << endl;
	}
	
	return 0;
}