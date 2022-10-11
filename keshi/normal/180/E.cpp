#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const int MAXM = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll int
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, m, k, a[MAXN], ans, e, l, r;

vector<ll> d[MAXM];

int main(){
	fast_io;
	
	cin >> n >> m >> k;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		d[a[i]].pb(i);
	}
	
	ans = 1;
	
	for(ll i = 1; i <= m; i++){
		e = 0;
		l = 0;
		r = 1;
		//cout << i << " => " << endl;
		while(l < d[i].size() && r < d[i].size()){
			//cout << "  " << l << " " << r << " => " << e + d[i][r] - d[i][r - 1] - 1 << endl;
			if(e + d[i][r] - d[i][r - 1] - 1 > k){
				e -= d[i][l + 1] - d[i][l] - 1;
				l++;
				r--;
			}
			else{
				//cout << "NOW" << endl;
				ans = max(ans, r - l + 1);
				e += d[i][r] - d[i][r - 1] - 1;
			}
			r++;
		}
	}
	
	cout << ans;
	
	
	return 0;
}