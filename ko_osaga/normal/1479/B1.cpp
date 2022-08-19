#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 998244353; //1e9 + 7;//998244353;
const int MAXN = 100005;

int n, a[MAXN], sum[MAXN];
int dp[MAXN];
int foo[MAXN];
const int MAXT = 270000;
struct seg{
	int tree[MAXT], lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		memset(tree, 0x3f, sizeof(tree));
	}
	int query(int s, int e){
		s += lim;
		e += lim;
		int ret = 1e9;
		while(s < e){
			if(s%2 == 1) ret = min(ret, tree[s++]);
			if(e%2 == 0) ret = min(ret, tree[e--]);
			s >>= 1; 
			e >>= 1;
		}
		if(s == e) ret = min(ret, tree[s]);
		return ret;
	}
	void upd(int x, int v){
		x += lim;
		while(x){
			tree[x] = min(tree[x], v);
			x >>= 1;
		}
	}
}seg;

int main(){
	fill(foo, foo + MAXN, -1e9);
	scanf("%d",&n);
	a[0] = n + 1;
	a[n + 1] = n + 2;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1; i <= n + 1; i++){
		sum[i] = sum[i - 1] + (a[i] == a[i - 1]);
	}
	int curMax = dp[0] - sum[1];
	seg.init(n + 3);
	seg.upd(a[0], dp[0] - sum[1]);
	for(int i = 1; i <= n; i++){
		dp[i] = min(seg.query(0, a[i+1] - 1), seg.query(a[i+1] + 1, n + 3));
		dp[i] = min(dp[i], seg.query(a[i+1], a[i+1]) + 1);
		dp[i] += sum[i];
		seg.upd(a[i], dp[i] - sum[i + 1]);
	}
	cout << n - dp[n] << endl;
}