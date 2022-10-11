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

ll n, ans;
string a, b;

int main(){
	fast_io;
	
	cin >> n;
	cin >> a >> b;
	
	for(ll i = 0; i < n; i++){
		if(a[i] != b[i]){
			ans++;
			if(i + 1 < n && a[i + 1] != b[i + 1] && a[i] != a[i + 1]){
				i++;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}