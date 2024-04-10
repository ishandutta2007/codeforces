//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, a, m, l[maxn];

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		fill(l, l + n + 1, -1);
		m = inf;
		for(ll i = 0; i < n; i++){
			cin >> a;
			if(l[a] == -1){
				l[a] = i;
			}
			else{
				m = min(m, i - l[a] + 1);
				l[a] = i;
			}
		}
		if(m == inf){
			m = -1;
		}
		cout << m << '\n';
	}
	
	return 0;
}