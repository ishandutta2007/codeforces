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

ll t, r;

string a, b;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> a >> b;
		for(ll i = 0; i < b.size(); i++){
			if(b[i] == '1'){
				r = b.size() - i - 1;
			}
		}
		for(ll k = 0; (int(a.size()) - r - k - 1) > -1; k++){
			if(a[a.size() - r - k - 1] == '1'){
				cout << k << endl;
				break;
			}
		}
	}
	
	return 0;
}