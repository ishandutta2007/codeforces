#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;

int n, k;
struct bit{
	int tree[1000005];
	void add(int x, int v){
		while(x <= n){
			tree[x] += v;
			x += x & -x;
		}
	}
	int query(int x){
		if(x > n) return query(n) + query(x-n);
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
	int solve(int x){
		return query(x + k - 1) - query(x);
	}
}bit;

int main(){
	cin >> n >> k;
	k = min(k, n-k);
	int pos = 1;
	lint ret = 1;
	for(int i=1; i<=n; i++){
		int t = pos - k +2 * n;
		while(t > n) t -= n;
		ret += 1 + bit.solve(pos) + bit.solve(t);
		printf("%lld ", ret);
		bit.add(pos, 1);
		pos += k;
		if(pos > n) pos -= n;
	}
}