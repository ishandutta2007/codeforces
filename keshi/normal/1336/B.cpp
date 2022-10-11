//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 8e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll m, n[3], a[3][maxn], t, q, p1, p2, p3, p4, ans;

ll cal(ll ca, ll cb, ll cc){
	return (ca - cb) * (ca - cb) + (ca - cc) * (ca - cc) + (cb - cc) * (cb - cc);
}

int main(){
	fast_io;
	
	cin >> m;
	
	while(m--){
		cin >> n[0] >> n[1] >> n[2];
		for(ll i = 0; i < 3; i++){
			for(ll j = 0; j < n[i]; j++){
				cin >> a[i][j];
			}
			sort(a[i], a[i] + n[i]);
		}
		ans = inf;
		for(ll j = 0; j < 3; j++){
			for(ll i = 0; i < n[j]; i++){
				t = (j + 1) % 3;
				q = (j + 2) % 3;
				p1 = lower_bound(a[t], a[t] + n[t], a[j][i]) - a[t];
				p2 = upper_bound(a[t], a[t] + n[t], a[j][i]) - 1 - a[t];
				p3 = lower_bound(a[q], a[q] + n[q], a[j][i]) - a[q];
				p4 = upper_bound(a[q], a[q] + n[q], a[j][i]) - 1 - a[q];
				if(0 <= p1 && p1 < n[t] && 0 <= p3 && p3 < n[q]) ans = min(ans, cal(a[j][i], a[t][p1], a[q][p3]));
				if(0 <= p1 && p1 < n[t] && 0 <= p4 && p4 < n[q]) ans = min(ans, cal(a[j][i], a[t][p1], a[q][p4]));
				if(0 <= p2 && p2 < n[t] && 0 <= p3 && p3 < n[q]) ans = min(ans, cal(a[j][i], a[t][p2], a[q][p3]));
				if(0 <= p2 && p2 < n[t] && 0 <= p4 && p4 < n[q]) ans = min(ans, cal(a[j][i], a[t][p2], a[q][p4]));
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}