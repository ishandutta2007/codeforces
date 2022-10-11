//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1111;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m;

bool p[maxn], vis[maxn];

vector<ll> v;

int main(){
	fast_io;
	
	p[1] = 1;
	
	for(ll i = 2; i < maxn; i++){
		if(!p[i]){
			v.pb(i);
			for(ll j = i * i; j < maxn; j += i){
				p[j] = 1;
			}
		}
	}
	
	cin >> n;
	
	m = *lower_bound(v.begin(), v.end(), n) - n;
	
	cout << m + n << '\n';
	
	for(ll i = 0; i < n; i++){
		cout << i + 1 << " " << (i + 1) % n + 1 << '\n';
		if(m && !vis[i] && !vis[(i + 2) % n]){
			vis[i] = 1;
			vis[(i + 2) % n] = 1;
			cout << i + 1 << " " << (i + 2) % n + 1 << '\n';
			m--;
		}
	}
	
	return 0;
}