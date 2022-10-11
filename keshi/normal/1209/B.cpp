//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e2 + 100;
const ll maxm = 1e4 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], b[maxn], s, ans;

string c;

bool t[maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	cin >> c;
	
	for(ll i = 0; i < n; i++){
		if(c[i] == '1'){
			t[i] = 1;
		}
	}
	
	for(ll i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	
	for(ll i = 0; i < maxm; i++){
		s = 0;
		for(ll j = 0; j < n; j++){
			if(i >= b[j] && (i - b[j]) % a[j] == 0){
				t[j] = !t[j];
			}
			if(t[j]){
				s++;
			}
		}
		ans = max(ans, s);
	}
	
	cout << ans;
	
	return 0;
}