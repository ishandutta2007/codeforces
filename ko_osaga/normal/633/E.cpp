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

int n, k, v[1000005], c[1000005];
int spv[1000005][20], spc[1000005][20];

int f[1000005];

int getfunc(int x){
	int cmax = -1e9, cmin = 1e9;
	int ret = -1e9;
	int pos = x;
	for(int i=19; i>=0; i--){
		if(pos + (1 << i) <= n){
			if(max(cmax, spv[pos][i]) <= min(cmin, spc[pos][i])){
				cmax = max(cmax, spv[pos][i]);
				cmin = min(cmin, spc[pos][i]);
				pos += (1<<i);
			}
		}
	}
	ret = max(ret, min(cmax, cmin));
	cmax = max(cmax, spv[pos][0]);
	cmin = min(cmin, spc[pos][0]);
	ret = max(ret, min(cmax, cmin));
	return ret;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++){
		scanf("%d",&v[i]);
		v[i] *= 100;
	}
	for(int i=0; i<n; i++){
		scanf("%d",&c[i]);
	}
	memset(spc, 0x3f, sizeof(spc));
	for(int i=n-1; i>=0; i--){
		spv[i][0] = v[i];
		spc[i][0] = c[i];
		for(int j=1; j<20; j++){
			spv[i][j] = spv[i][j-1], spc[i][j] = spc[i][j-1];
			if(i + (1 << (j-1)) >= n) break;
			spv[i][j] = max(spv[i][j], spv[i + (1<<(j-1))][j-1]);
			spc[i][j] = min(spc[i][j], spc[i + (1<<(j-1))][j-1]);
		}
	}
	for(int i=0; i<n; i++){
		f[i] = getfunc(i);
	}
	sort(f, f+n);
	double prob = 1.0 * k / n;
	double ret = 0;
	for(int i=0; i<=n-k; i++){
		ret += prob * f[i];
		prob *= n-k-i;
		if(n-1 != i) prob /= n-1-i;
	}
	printf("%.20f",ret);
}