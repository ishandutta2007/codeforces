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

int n, a[200005];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a, a+n);
	n = unique(a, a+n) - a;
	int r = 0;
	for(int i=0; i<n; i++){
		for(int j=2*a[i]; j<=1000000; j+=a[i]){
			int l = lower_bound(a, a+n, j) - a;
			if(l-1 >= i) r = max(r, a[l-1] % a[i]);
		}
		r = max(r, a[n-1] % a[i]);
	}
	cout << r;
}