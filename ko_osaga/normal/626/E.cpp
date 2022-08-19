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
const int mod = 1e9 + 9;

int n;
int a[200005];
lint s[200005];

int max_mean(int s1, int e1, int s2, int e2, int offset){
	int sz = min(e1 - s1 + 1, e2 - s2 + 1);
	int st = 0, ed = sz;
	while(st != ed){
		int m = (st+ed)/2;
		llf t1 = s[e2] - s[e2-m] + s[e1+offset] - s[e1-m];
		t1 /= 2 * m + offset;
		llf t2 = s[e2] - s[e2-m-1] + s[e1+offset] - s[e1-m-1];
		t2 /= 2 * m + 2 + offset;
		if(t1 <= t2){
			st = m+1;
		}
		else ed = m;
	}
	return st;
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++){
		s[i] = s[i-1] + a[i];
	}
	llf ret = -1e9;
	int rp = -1, rs = -1;
	for(int i=1; i<=n; i++){
		int tmp = max_mean(1, i-1, i+1, n, 1);
		llf sol = llf(s[n] - s[n-tmp] + s[i] - s[i-1-tmp]) / (2.0 * tmp + 1) - a[i];
		if(ret < sol){
			ret = sol;
			rp = 2 * i;
			rs = tmp;
		}
	}
	for(int i=1; i<n; i++){
		int tmp = max_mean(1, i-1, i+2, n, 2);
		llf sol = llf(s[n] - s[n-tmp] + s[i+1] - s[i-1-tmp]) / (2.0 * tmp + 2) - a[i] - a[i+1];
		if(ret < sol){
			ret = sol;
			rp = 2 * i + 1;
			rs = tmp;
		}
	}
	if(rp % 2 == 1){
		printf("%d\n",rs * 2 + 2);
		printf("%d %d ",a[rp/2], a[rp/2+1]);
		for(int i=0; i<rs; i++){
			printf("%d %d ",a[n-i], a[rp/2-i-1]);
		}
	}
	if(rp % 2 == 0){
		printf("%d\n",rs * 2 + 1);
		printf("%d ",a[rp/2]);
		for(int i=0; i<rs; i++){
			printf("%d %d ",a[n-i], a[rp/2-i-1]);
		}
	}
}