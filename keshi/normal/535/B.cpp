#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, ans;

string s;

int main(){
	fast_io;
	
	cin >> s;
	
	n = s.size();
	
	ans = pow(2, n) - 1;
	
	for(ll i = 0; i < n; i++){
		if(s[i] == '7'){
			ans += pow(2, n - i - 1);
		}
	}
	
	cout << ans;
	
	return 0;
}