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

struct bit{
	int tree[1000005];
	void add(int x, int v){
		x++;
		while(x <= 1000001){
			tree[x] += v;
			tree[x] %= mod;
			x += x & -x;
		}
	}
	int query(int x){
		x++;
		int ret = 0;
		while(x){
			ret += tree[x];
			ret %= mod;
			x -= x & -x;
		}
		return ret;
	}
}bit;

int n, dp[100005];
pi a[100005];

int main(){
	scanf("%d",&n);
	bit.add(0, 1);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++){
		int e = i;
		while(e <= n && a[e].first == a[i].first) e++;
		for(int j=i; j<e; j++){
			if(a[j-1].first == a[j].first){
				dp[j] = 1ll * dp[j-1] * a[j].first % mod
				+ 1ll * (bit.query(a[j].second - 1) - bit.query(a[j-1].second - 1) + mod) * a[j].first % mod;
			}
			else{
				dp[j] = 1ll * bit.query(a[j].second - 1) * a[j].first % mod;
			}
			dp[j] %= mod;
		}
		for(int j=i; j<e; j++) bit.add(a[j].second, dp[j]);
		i = e-1;
	}
	cout << (bit.query(n) + mod - 1) % mod;
}