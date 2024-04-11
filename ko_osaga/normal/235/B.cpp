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

int n;
double p[100005];
double dp[100005];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%lf",&p[i]);
	}
	double dpc = 0;
	double poly2 = 1.0 * (n+1) * (n+1) * p[n];
	double poly1 = 1.0 * (n+1) * p[n];
	double poly0 = p[n];
	for(int i=n; i; i--){
		dp[i] = dpc + poly2 - 2 * i * poly1 + 1.0 * i * i * poly0;
		dpc = dpc * p[i-1] + dp[i] * (1 - p[i-1]);
		poly2 += (1 - p[i]) * i * i;
		poly2 *= p[i-1];
		poly1 += (1 - p[i]) * i;
		poly1 *= p[i-1];
		poly0 += 1 - p[i];
		poly0 *= p[i-1];
	}
	printf("%.10f",dp[1]);
}