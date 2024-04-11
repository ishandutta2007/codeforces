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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n;
int s[100005], e[100005], x[100005];
vector<pi> gph[100005];
int size[100005];

void dfs(int x, int p){
	size[x] = 1;
	for(auto &i : gph[x]){
		if(i.second == p) continue;
		dfs(i.second, x);
		size[x] += size[i.second];
	}
}

int main(){
	cin >> n;
	for(int i=1; i<=n-1; i++){
		cin >> s[i] >> e[i] >> x[i];
		gph[s[i]].push_back(pi(x[i], e[i]));
		gph[e[i]].push_back(pi(x[i], s[i]));
	}
	dfs(1, 0);
	lint ret = 0;
	for(int i=1; i<=n-1; i++){
		int sz = min(size[s[i]], size[e[i]]);
		ret += 1ll * sz * (n - sz) * x[i];
	}
	int q;
	cin >> q;
	while(q--){
		int r, w;
		cin >> r >> w;
		int sz = min(size[s[r]], size[e[r]]);
		ret += 1ll * (w - x[r]) * (n - sz) * sz;
		x[r] = w;
		printf("%.20f\n",6.0 * ret / (1.0 * n * (n-1)));
	}
}