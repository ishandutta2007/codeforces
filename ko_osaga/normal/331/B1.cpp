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

int n, q, a[300005], r[300005];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		r[a[i]] = i;
	}
	scanf("%d",&q);
	while(q--){
		int p, x, y;
		scanf("%d %d %d",&p,&x,&y);
		if(p == 1){
			int cnt = 0;
			for(int i=x; i<y; i++){
				if(r[i] > r[i+1]) cnt++;
			}
			printf("%d\n",cnt+1);
		}
		else{
			swap(a[x], a[y]);
			swap(r[a[x]], r[a[y]]);
		}
	}
}