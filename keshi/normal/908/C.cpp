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
#define x first
#define y second

ll n, r;

pair<long double, long double> a[maxn];

int main(){
	fast_io;
	cout << fixed << setprecision(10);
	
	cin >> n >> r;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].x;
		a[i].y = r;
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < i; j++){
			if(abs(a[i].x - a[j].x) <= 2 * r){
				a[i].y = max(a[i].y, a[j].y + sqrt(4 * r * r - (a[i].x - a[j].x) * (a[i].x - a[j].x)));
			}
		}
		cout << a[i].y << " ";
	}
	
	return 0;
}