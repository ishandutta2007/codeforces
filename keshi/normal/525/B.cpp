#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

typedef long long ll;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, x, a[maxn];

string s;

int main(){
	fast_io;
	
	cin >> s >> m;
	
	n = s.size();
	
	for(ll i = 0; i < m; i++){
		cin >> a[i];
		a[i]--;
	}
	
	sort(a, a + m);
	
	for(ll i = 0; i * 2 < n; i++){
		while(x < m && a[x] <= i){
			x++;
		}
		if(x % 2){
			swap(s[i], s[n - i - 1]);
		}
	}
	cout << s;
	
	return 0;
}