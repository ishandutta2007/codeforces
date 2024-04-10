//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
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

int t, n, a[maxn], c[maxn], c2[maxn];

int main(){
	fast_io;

	cin >> t;
	while(t--){
		cin >> n;
		fill(c, c + n + 10, 0);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			c[a[i]]++;
		}
		int ls = n + 2;
		int l = 0;
		vector<int> vec;
		while(l < n){
			for(int i = 0; i <= ls; i++){
				if(c[i] == 0){
					ls = i;
					break;
				}
			}
			int cc = 0;
			fill(c2, c2 + ls + 5, 0);
			while(cc < ls){
				c[a[l]]--;
				if(a[l] < ls && c2[a[l]] == 0) cc++;
				c2[a[l]]++;
				l++;
			}
			if(ls == 0) c[a[l++]]--;
			vec.pb(ls);
		}
		cout << Sz(vec) << "\n";
		for(int i : vec){
			cout << i << " ";
		}
		cout << "\n";
	}
	
	return 0;
}