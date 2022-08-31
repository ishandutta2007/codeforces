#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 2100005;

/*
struct seg{
	int tree[MAXN];
	int lim;
	void init(vector<int> &v){
		for(lim = 1; lim < sz(v); lim <<= 1);
		fill(tree, tree + MAXN, -1e9);
		for(int i = 0; i < sz(v); i++) tree[i + lim] = v[i];
		for(int i = lim-1; i; i--) tree[i] = max(tree[2*i], tree[2*i+1]);
	}
	int query(int s, int e){
		s += lim;
		e += lim;
		int ret = -1e9;
		while(s < e){
			if(s%2 == 1) ret = max(ret, tree[s++]);
			if(e%2 == 0) ret = max(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = max(ret, tree[s]);
		return ret;
	}
}seg;

char buf[MAXN];
int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	vector<string> v(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(m));
	for(int i = 1; i <= n; i++){
		scanf("%s", buf);
		v[i] = string(buf);
	}
	vector<int> val(m);
	for(int i = 0; i < m; i++) dp[0][i] = -1e9, val[i] = -1e9;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			if(v[i][j] == 'X') dp[i][j] = 1e9;
			else{
				dp[i][j] = dp[i - 1][j];
				if(j) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			//	else dp[i][j] = -1e9;
				dp[i][j] = min(dp[i][j], j);
				val[j] = max(val[j], dp[i][j]);
			}
		}
	}
	seg.init(val);
	int q; scanf("%d",&q);
	while(q--){
		int l, r; scanf("%d %d",&l,&r);
		l--; r--;
		int minv = seg.query(l, r);
		if(minv > l) puts("NO");
		else puts("YES");
	}
}*/

int main(){
	int tc; scanf("%d",&tc);
	for(int i = 0; i < tc; i++){
		int n, m;
		set<int> s;
		scanf("%d %d",&n,&m);
		for(int i = 0; i < m; i++){
			int x;
			scanf("%*d %d %*d",&x);
			s.insert(x);
		}
		int p = 1;
		while(s.find(p) != s.end()) p++;
		for(int i = 1; i <= n; i++){
			if(i != p) printf("%d %d\n", i, p);
		}
	}
}