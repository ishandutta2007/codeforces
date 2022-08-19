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
typedef pair<lint, lint> pi;

int n, a[200005], k;

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	lint rsum = 0, sz = 0;
	for(int i=1; i<=n; i++){
		if(rsum - sz * (n - i) * a[i] < k){
			printf("%d\n",i);
		}
		else{
			sz++;
			rsum += 1ll * a[i] * (sz - 1);
		}
	}
}