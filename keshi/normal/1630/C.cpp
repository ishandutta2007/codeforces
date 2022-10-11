//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int n, a[maxn], b[maxn], c[maxn], ans;

int main(){
	fast_io;

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = n; i--;){
		if(b[a[i]]){
			c[i] = b[a[i]];
		}
		else{
			c[i] = -1;
			b[a[i]] = i;
		}
	}
	{
		int i = 0;
		int l = 0;
		while(i < n){
			int r = c[i];
			if(r == -1){
				i++;
				continue;
			}
			if(l <= i) l = i + 1;
			int mx = i, cn = 0;
			while(l < r){
				if(c[l] > c[mx]){
					mx = l;
				}
				l++;
				cn++;
			}
			if(mx != i){
				i = mx;
				ans += cn - 1;
			}
			else{
				i = r + 1;
				ans += cn;
			}
		}
	}
	cout << ans << "\n";
	
	return 0;
}