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
#define F first
#define S second

ll t, n, a[MAXN], k, d, p;

int main(){
	fast_io;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		d = INF;
		for(int i = 0; i + k < n; i++){
			if(a[i + k] - (a[i] + a[i + k]) / 2 < d){
				d = a[i + k] - (a[i] + a[i + k]) / 2;
				p = (a[i] + a[i + k]) / 2;
			}
		}
		cout << p << endl;
	}
	return 0;
}