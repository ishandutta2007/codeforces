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
typedef pair<lint, int> pi;
#define div fuck

// l, r  pick ->  
// l, r  not pick -> 
int n, m, k, p;
lint r[1005], c[1005];
lint dp1[1000005], dp2[1000005];

void solve(lint *inp, int n, int m, lint *ret){
	priority_queue<pi> pq;
	for(int i=0; i<n; i++){
		pq.push(pi(inp[i], i));
	}
	for(int i=1; i<=k; i++){
		pi t = pq.top();
		pq.pop();
		ret[i] = ret[i-1] + t.first;
		inp[t.second] -= m * p;
		pq.push(pi(inp[t.second], t.second));
	}
}

int main(){
	cin >> n >> m >> k >> p;
	for(int i=0; i<n; i++){
		int t;
		for(int j=0; j<m; j++){
			scanf("%d",&t);
			r[i] += t; c[j] += t;
		}
	}
	solve(r, n, m, dp1);
	solve(c, m, n, dp2);
	lint ret = -1e18;
	for(int i=0; i<=k; i++){
		ret = max(ret, dp1[i] + dp2[k-i] - 1ll * i * (k-i) * p);
	}
	cout << ret;
}