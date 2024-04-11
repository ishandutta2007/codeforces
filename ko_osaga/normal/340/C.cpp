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
const int mod = 1e9 + 7;

int n, a[100005];

lint g(lint x, lint y){
	return y ? g(y, x%y) : x;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	sort(a, a+n);
	lint ret = 0;
	for(int i=0; i<n; i++){
		ret += a[i];
	}
	lint sm = 0;
	for(int i=n-1; i>=0; i--){
		sm += 2 * a[i];
		ret += sm - 2ll * (n - i) * a[i];
	}
	int gcd = g(ret, n);
	ret /= gcd, n /= gcd;
	printf("%lld %d", ret, n);
}