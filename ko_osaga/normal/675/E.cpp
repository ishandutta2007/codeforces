#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, a[100005];
lint dp[100005];

struct seg{
	lint tree[270000];
	int lim;
	void init(int n){
		memset(tree, 0x3f, sizeof(tree));
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void add(int x, lint v){
		x += lim;
		tree[x] = min(tree[x], v);
		while(x > 1){
			x >>= 1;
			tree[x] = min(tree[2*x], tree[2*x+1]);
		}
	}
	lint query(int s, int e){
		s += lim;
		e += lim;
		lint ret = 1e18;
		while(s < e){
			if(s%2 == 1) ret = min(ret, tree[s++]);
			if(e%2 == 0) ret = min(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = min(ret, tree[s]);
		return ret;
	}
}seg;

int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		scanf("%d",&a[i]);
	}
	seg.init(n);
	seg.add(n, n);
	lint ret = 0;
	for(int i=n-1; i; i--){
		dp[i] = seg.query(i+1, a[i]) - i - a[i] + n;
		ret += dp[i];
		seg.add(i, dp[i] + i);
	}
	cout << ret;
}