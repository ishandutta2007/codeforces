// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
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

ll n, f;
vector<ll> a[2000];

void solve(ll l, ll r, ll d){
	//cout << l << " " << r << endl;
	if(r - l <= 1){
		return;
	}
	f = max(f, d);
	for(ll i = l; i < (l + r) / 2; i++){
		a[d].pb(i + 1);
	}
	solve(l, (l + r) / 2, d + 1);
	solve((l + r) / 2, r, d + 1);
	return;
}

int main(){
	fast_io;
	file_io;
	
	cin >> n;
	
	solve(0, n, 0);
	
	cout << f + 1 << endl;
	for(ll i = 0; i < f + 1; i++){
		cout << a[i].size() << " ";
		for(ll j = 0; j < a[i].size(); j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}