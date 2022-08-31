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

int n, m, k;
lint a[100005];
lint l[100005], r[100005], d[100005];
lint dx[100005], dx2[100005];

int main(){
	cin >> n >> m >> k;
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1; i<=m; i++){
		scanf("%lld %lld %lld",&l[i], &r[i], &d[i]);
	}
	for(int i=0; i<k; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		dx[s]++;
		dx[e+1]--;
	}
	for(int i=1; i<=m; i++){
		dx[i]+= dx[i-1];
		d[i] *= dx[i];
		dx2[l[i]] += d[i];
		dx2[r[i]+1] -= d[i];
	}
	for(int i=1; i<=n; i++){
		dx2[i] += dx2[i-1];
		printf("%lld ",dx2[i] + a[i]);
	}
}