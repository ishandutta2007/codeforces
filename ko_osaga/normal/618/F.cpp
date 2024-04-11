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
typedef pair<int, int> pi;

int n;
lint a[1000005], b[1000005];

struct t1{
	int i1, i2;
	lint val;
}v[1000005];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
		a[i] += a[i-1];
	}
	for(int i=1; i<=n; i++){
		scanf("%lld",&b[i]);
		b[i] += b[i-1];
	}
	bool swp = 0;
	for(int i=1; i<=n; i++){
		if(a[n] > b[n]){
			swap(a[i], b[i]);
			swp = 1;
		}
	}
	int p = 0;
	for(int i=0; i<=n; i++){
		while(b[p] < a[i]) p++;
		v[i] = {i, p, b[p] - a[i]};
		if(swp) swap(v[i].i1, v[i].i2);
	}
	sort(v, v + n + 1, [&](const t1 &a, const t1 &b){
		return pi(a.val, a.i1) < pi(b.val, b.i1);
	});
	for(int i=0; i<=n; i++){
		int e = i;
		while(e <= n && v[e].val == v[i].val) e++;
		if(e - i >= 2){
			int s = v[i].i1, e = v[i+1].i1;
			printf("%d\n",e - s);
			for(int j=s+1; j<=e; j++){
				printf("%d ",j);
			}
			s = v[i].i2, e = v[i+1].i2;
			printf("\n%d\n",e - s);
			for(int j=s+1; j<=e; j++){
				printf("%d ",j);
			}
			return 0;
		}
	}
	// a[i]
}