#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, m, k, a[MAXN][5], b[MAXN][5];
deque<ll> dq;

ll cal(ll x){
	ll ans = INF, s;
	
	for(ll j = 0; j < m; j++){
		dq.clear();
		for(ll i = 0; i < n; i++){
			while(!dq.empty() && a[dq.back()][j] <= a[i][j]){
				dq.pop_back();
			}
			if(!dq.empty() && i - dq.front() >= x){
				dq.pop_front();
			}
			dq.push_back(i);
			b[i][j] = a[dq.front()][j];
		}
	}
	
	for(ll i = x - 1; i < n; i++){
		s = 0;
		for(ll j = 0; j < m; j++){
			s += b[i][j];
			//cout << b[i][j] << " ";
		}
		//cout << " ----> " << s << endl;
		ans = min(ans, s);
	}
	
	return ans;
}

ll isval(ll x){
	//cout << x << " => " << cal(x) << endl;
	return cal(x) > k;
}

ll binary_search(){
	ll l = 0, r = n, mi;
	while(r - l > 1){
		//cout << l << " " << r << endl;
		mi = (l + r) / 2;
		if(isval(mi)){
			r = mi;
		}
		else{
			l = mi;
		}
	}
	return l;
}

void solve(ll x){
	
	ll ans = INF, s;
	
	for(ll j = 0; j < m; j++){
		dq.clear();
		for(ll i = 0; i < n; i++){
			while(!dq.empty() && a[dq.back()][j] <= a[i][j]){
				dq.pop_back();
			}
			if(!dq.empty() && i - dq.front() >= x){
				dq.pop_front();
			}
			dq.push_back(i);
			b[i][j] = a[dq.front()][j];
		}
	}
	
	for(ll i = x - 1; i < n; i++){
		s = 0;
		for(ll j = 0; j < m; j++){
			s += b[i][j];
		}
		if(s <= k){
			for(ll j = 0; j < m; j++){
				cout << b[i][j] << " ";
			}
			return;
		}
	}
	
	for(ll i = 0; i < m; i++){
		cout << 0 << " ";
	}
	
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m >> k;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	
	solve(binary_search());
	
	return 0;
}