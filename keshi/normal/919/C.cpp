#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 100;
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

ll n, m, e, l, ans;
string a[MAXN];

int main(){
	fast_io;
	
	cin >> n >> m >> e;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		a[i] += '*';
		l = -1;
		for(ll j = 0; j < m + 1; j++){
			if(a[i][j] == '*'){
				ans += max(e - e, j - l - e);
				l = j;
			}
		}
	}
	a[n] = "";
	for(int i = 0; i < m + 1; i++){
		a[n] += '*';
	}
	for(ll j = 0; j < m; j++){
		l = -1;
		for(ll i = 0; i < n + 1; i++){
			if(a[i][j] == '*'){
				ans += max(e - e, i - l - e);
				l = i;
			}
		}
	}
	if(e == 1){
		ans = ans / 2;
	}
	cout << ans;
	return 0;
}