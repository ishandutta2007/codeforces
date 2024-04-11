#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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
typedef pair<llf, llf> pi;

int n;
vector<int> gph[100005];
lint dp1[100005], dp2[100005], a[100005];

lint dfs(int x, int p){
	lint ret = 0;
	for(auto &i : gph[x]){
		if(i == p) continue;
		ret += dfs(i, x);
		dp1[x] = max(dp1[x], dp1[i]); // increase
		dp2[x] = max(dp2[x], dp2[i]); // decrease
	}
	if(a[x] + dp1[x] - dp2[x] < 0){
		dp1[x] -= a[x] + dp1[x] - dp2[x];
	}
	else{
		dp2[x] += a[x] + dp1[x] - dp2[x];
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s, &e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	dfs(1, -1);
	cout << dp1[1] + dp2[1];
}