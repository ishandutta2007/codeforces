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

int main(){
	int n;
	char str[100005];
	unsigned dp[50005] = {};
	scanf("%d %s",&n, str + 1);
	if(n%2){
		puts("0");
		return 0;
	}
	dp[0] = 1;
	for(int i=1; i<=n; i++){
		if(str[i] != '?') continue;
		for(int j=i/2; j; j--){
			dp[j] = dp[j] * 25u + dp[j-1];
		}
		dp[0] = dp[0] * 25u;
	}
	printf("%u",dp[n/2]);
}