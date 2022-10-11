//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 4e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, c, t, m;

string s;

map<char,ll> cnt;

deque<char> d[maxn];

int main(){
	fast_io;
	
	cin >> n >> s;
	
	for(ll i = 0; i < n; i++){
		cnt[s[i]]++;
	}
	
	for(map<char, ll>::iterator it = cnt.begin(); it != cnt.end(); it++){
		if(it -> S % 2) c++;
	}
	
	if(c == 0){
		cout << 1 << endl;
		for(map<char, ll>::iterator it = cnt.begin(); it != cnt.end(); it++){
			for(ll i = 0; i * 2 < it -> S; i++){
				d[0].pb(it -> F);
			}
			for(ll i = 0; i * 2 < it -> S; i++){
				d[0].push_front(it -> F);
			}
		}
		for(ll i = 0; i < d[0].size(); i++){
			cout << d[0][i];
		}
		return 0;
	}
	
	for(ll i = n; i > 0; i--){
		if(n % i == 0 && i % 2 && n / i >= c && (n / i - c) % 2 == 0){
			m = n / i;
			for(map<char, ll>::iterator it = cnt.begin(); it != cnt.end(); it++){
				if(it -> S % 2){
					d[t++].pb(it -> F);
					it -> S --;
				}
			}
			for(map<char, ll>::iterator it = cnt.begin(); it != cnt.end(); it++){
				while(it -> S && t < m){
					d[t++].pb(it -> F);
					it -> S--;
					d[t++].pb(it -> F);
					it -> S--;
				}
			}
			t = 0;
			for(map<char, ll>::iterator it = cnt.begin(); it != cnt.end(); it++){
				while(it -> S && t < m){
					d[t].pb(it -> F);
					it -> S -= 2;
					if(d[t].size() * 2 >= i){
						t++;
					}
				}
			}
			cout << m << endl;
			for(ll j = 0; j < m; j++){
				for(ll k = d[j].size() - 1; k > 0; k--){
					cout << d[j][k];
				}
				for(ll k = 0; k < d[j].size(); k++){
					cout << d[j][k];
				}
				cout << " ";
			}
			return 0;
		}
	}
	
	return 0;
}