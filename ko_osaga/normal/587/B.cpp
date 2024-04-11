#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

vector<vector<int> > dp;
int n, k, a[1000005];
lint l;
vector<int> coord;

struct bit{
	int tree[1000005];
	void init(){
		fill(tree, tree + n + 1, 0);
	}
	void add(int x, int v){
		while(x <= n){
			tree[x] += v;
			tree[x] %= mod;
			x += x & -x;
		}
	}
	int sum(int x){
		int r = 0;
		while(x){
			r += tree[x];
			r %= mod;
			x -= x & -x;
		}
		return r;
	}
}bit;

int main(){
	scanf("%d %lld %d",&n,&l,&k);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		coord.push_back(a[i]);
	}
	sort(coord.begin(), coord.end());
	coord.resize(unique(coord.begin(), coord.end()) - coord.begin());
	for(int i=0; i<n; i++){
		a[i] = lower_bound(coord.begin(), coord.end(), a[i]) - coord.begin() + 1;
	}
	dp.resize(k+1);
	dp[1].resize(n, 1);
	for(int i=2; i<=k; i++){
		dp[i].resize(n);
		bit.init();
		for(int j=0; j<n; j++){
			bit.add(a[j], dp[i-1][j]);
		}
		for(int j=0; j<n; j++){
			dp[i][j] = bit.sum(a[j]);
		}
	}
	lint ret = 0;
	for(int i=1; i<=k && i <= l/n+1; i++){
		for(int j=0; j<n; j++){
			ret += 1ll * ((l/n - i + 1) % mod) * dp[i][j] % mod;
			if(j < l%n) ret += 1ll * dp[i][j] % mod;
		}
		ret %= mod;
	}
	printf("%lld",ret);
}