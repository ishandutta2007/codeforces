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

ll q, n, a[maxn], r, t;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n >> r;
		
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		a[n] = -1;
		t = 0;
		for(ll i = n - 1; i > -1; i--){
			if(t * r < a[i] && a[i + 1] != a[i]){
				t++;
			}
		}
		cout << t << endl;
	}
	
	return 0;
}