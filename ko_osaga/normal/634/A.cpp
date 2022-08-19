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
const int mod = 1e9 + 7;

int n, a[200005], b[200005];
int ta[200005], tb[200005], sz;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		if(a[i]) ta[sz++] = a[i];
	}
	sz = 0;
	for(int i=0; i<n; i++){
		scanf("%d",&b[i]);
		if(b[i]) tb[sz++] = b[i];
	}
	n--;
	rotate(ta, min_element(ta, ta+n), ta+n);
	rotate(tb, min_element(tb, tb+n), tb+n);
	for(int i=0; i<n; i++){
		if(ta[i] != tb[i]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}