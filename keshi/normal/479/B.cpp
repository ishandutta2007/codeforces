#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 110;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, j;

pll a[maxn];

vector<pll> m;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].F;
		a[i].S = i;
	}
	sort(a, a + n);
	
	for(ll i = 0; i < k; i++){
		if(a[n - 1].F - a[0].F <= 1){
			cout << a[n - 1].F - a[0].F << " " << m.size() << endl;
			for(j = 0; j < m.size(); j++){
				cout << m[j].F << " " << m[j].S << endl;
			}
			return 0;
		}
		m.pb({a[n - 1].S + 1, a[0].S + 1});
		a[0].F++;
		j = 0;
		while(a[j] > a[j + 1]){
			swap(a[j], a[j + 1]);
			j++;
		}
		a[n - 1].F--;
		j = n - 1;
		while(a[j] < a[j - 1]){
			swap(a[j], a[j - 1]);
			j--;
		}
	}
	
	cout << a[n - 1].F - a[0].F << " " << k << endl;
	
	for(ll i = 0; i < k; i++){
		cout << m[i].F << " " << m[i].S << endl;
	}
	
	return 0;
}