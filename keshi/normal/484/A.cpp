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

ll q, l, r, d, p[60], ans;

bool b[60];

int main(){
	fast_io;
	
	p[0] = 1;
	for(ll i = 1; i < 60; i++){
		p[i] = p[i - 1] * 2;
	}
	
	cin >> q;
	
	while(q--){
		cin >> l >> r;
		d = r - l;
		for(ll i = 0; i < 60; i++){
			b[i] = l % 2;
			l /= 2;
		}
		for(ll i = 0; i < 60; i++){
			if(b[i] == 0){
				if(d >= p[i]){
					d -= p[i];
					b[i] = 1;
				}
			}
		}
		ans = 0;
		for(ll i = 0; i < 60; i++){
			if(b[i]){
				ans += p[i];
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}