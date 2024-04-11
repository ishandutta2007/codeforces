#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n;
int adj[505][505];
int x[505];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%d",&adj[i][j]);
		}
	}
	for(int i=1; i<=n; i++) scanf("%d",&x[i]);
	reverse(x+1, x+n+1);
	stack<lint> dap;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				adj[x[j]][x[k]] = min(adj[x[j]][x[k]], adj[x[j]][x[i]] + adj[x[i]][x[k]]);
			}
		}
		lint ret = 0;
		for(int j=1; j<=i; j++){
			for(int k=1; k<=i; k++){
				ret += adj[x[j]][x[k]];
			}
		}
		dap.push(ret);
	}
	while(!dap.empty()){
		printf("%lld ",dap.top());
		dap.pop();
	}
}