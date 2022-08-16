#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n), b(n), p(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			a[i]--;
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
			b[i]--;
			p[a[i]] = b[i];
		}
		vector<int> vis(n);
		int ans = 1;
		for(int i = 0; i < n; i++) if(!vis[i]){
			ans = mul(ans, 2);
			int j = i;
			while(!vis[j]){
				vis[j] = 1;
				j = p[j];
			}
		}
		cout << ans << endl;
	}
}