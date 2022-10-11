//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, a[maxn];

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		bool f = 1;
		for(ll i = 1; i < n; i++){
			if(a[i] == a[i - 1] + 1){
				f = 0;
			}
		}
		if(f){
			cout << 1;
		}
		else{
			cout << 2;
		}
		cout << endl;
	}
	
	return 0;
}