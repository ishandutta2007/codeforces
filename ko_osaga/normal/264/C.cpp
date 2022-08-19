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

int n, q;
lint v[100005], c[100005];
lint colmax[100005], max1, max2;
int maxp1, maxp2;

int main(){
	scanf("%d %d",&n,&q);
	for(int i=1; i<=n; i++){
		scanf("%lld",&v[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%lld",&c[i]);
	}
	while(q--){
		int a, b;
		scanf("%d %d",&a,&b);
		max1 = max2 = 0;
		maxp1 = maxp2 = -1;
		fill(colmax, colmax + n + 1, -1e18);
		for(int i=1; i<=n; i++){
			lint q1 = max1 + v[i] * (maxp1 == c[i] ? a : b);
			lint q2 = max2 + v[i] * (maxp2 == c[i] ? a : b);
			lint dp = max(max(q1, q2), colmax[c[i]] + v[i] * a);
			colmax[c[i]] = max(colmax[c[i]], dp);
			if(dp > max1){
				if(maxp1 != c[i]){
					max2 = max1;
					maxp2 = maxp1;
				}
				max1 = dp;
				maxp1 = c[i];
			}
			else if(dp > max2){
				if(maxp1 != c[i]){
					max2 = dp;
					maxp2 = c[i];
				}
			}
		}
		printf("%lld\n",max1);
	}
}