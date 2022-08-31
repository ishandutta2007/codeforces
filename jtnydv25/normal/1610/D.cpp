#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif
const int mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n; cin>> n;
	vector<int> a(n);
	for(int& x: a) cin >> x;
	vector<int> vals(30);
	for(int i = 0; i < n; i++){
		int r = 0;
		while(a[i] % 2 == 0){
			a[i] /= 2;
			r++;
		}
		vals[r]++;
	}
	
	int bad = 1;
	int k = 0;
	for(int i = 29; i >= 1; i--){
		if(vals[i] > 0){
			bad = add(bad, powr(2, vals[i] + k - 1));
		}
		k += vals[i];
	}
	cout << sub(powr(2, n), bad) << endl;
}