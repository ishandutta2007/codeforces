#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e5 + 20, mlg = 18, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
struct vec5 {
	int a[5];
	void get() {
		for(int i = 0; i < 5; i++) cin >> a[i];
	}
	vec5 sub(vec5 s) {
		vec5 t = *this;
		for(int i = 0; i < 5; i++)
			t.a[i] -= s.a[i];
		return t;
	}
	int dot(vec5 s) {
		int res = 0;
		for(int i = 0; i < 5; i++)
			res += a[i]*s.a[i];
		return res;
	}

};
int n, p[1010];
vec5 mat[1010];
vi g;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) mat[i].get(), p[i] = i;
	for(int i = 1; i <= n; i++){
		int ok = 1;
		for(int j = 1; ok && j <= n; j++) {
			for(int k = 1; ok && k <= n; k++) {
				if(i==j||j==k||i==k) continue;
				if(mat[j].sub(mat[i]).dot(mat[k].sub(mat[i]))>0) ok = 0;//, cout << i << " " << j << " " << k << "\n";
			}
		}
		if(ok) g.pb(i);
	}
	cout << g.size() << "\n";
	for(auto i : g) cout << i << "\n";
	return 0;
}