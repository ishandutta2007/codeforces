//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 200;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, m, c[26], cnt[maxn][26];

bool f, h;

string s, t;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> s >> t;
		n = s.size();
		m = t.size();
		fill(c, c + 26, 0);
		for(ll i = 0; i < maxn; i++){
			fill(cnt[i], cnt[i] + 26, 0);
		}
		for(ll i = 0; i < n; i++){
			c[s[i] - 'a']++;
		}
		for(ll i = 1; i <= m; i++){
			for(ll j = 0; j < 26; j++){
				cnt[i][j] = cnt[i - 1][j];
			}
			cnt[i][t[i - 1] - 'a']++;
		}
		h = 0;
		for(ll i = 0; i + n <= m; i++){
			f = 1;
			for(ll j = 0; j < 26; j++){
				if(c[j] != cnt[i + n][j] - cnt[i][j]) f = 0;
			}
			if(f) h = 1; 
		}
		if(h) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}