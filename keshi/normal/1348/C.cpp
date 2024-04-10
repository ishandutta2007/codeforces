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

ll q, n, k;

bool f;

string s;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n >> k >> s;
		sort(s.begin(), s.end());
		cout << s[k - 1];
		if(s[k - 1] != s[0]){
			cout << '\n';
			continue;
		}
		f = 0;
		for(ll i = k; i + 1 < n; i++){
			if(s[i] != s[i + 1]) f = 1;
		}
		if(f){
			for(ll j = k; j < n; j++){
				cout << s[j];
			}
		}
		else{
			for(ll i = 0; i * k < n - k; i++){
				cout << s[k];
			}
		}
		cout << '\n';
	}
	
	return 0;
}