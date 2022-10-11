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

ll n, a[maxn], cnt[maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	
	for(ll i = 1; i + 1 < maxn; i++){
		if(cnt[i] < cnt[i + 1]){
			cout << -1;
			return 0;
		}
	}
	
	cout << cnt[1] << endl;
	
	fill(cnt, cnt + maxn, 0);
	
	for(ll i = 0; i < n; i++){
		cout << ++cnt[a[i]] << " ";
	}
	
	return 0;
}