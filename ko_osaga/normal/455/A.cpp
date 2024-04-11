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
typedef pair<lint, lint> pi;
const int mod = 999983;

int n, a[100005];
lint dp[100005];
int main(){
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		a[x]++;
	}
	for(int i=1; i<=100000; i++){
		if(a[i]){
			dp[i] = dp[i-2] + 1ll * a[i] * i;
		}
		dp[i] = max(dp[i], dp[i-1]);
	}
	cout << dp[100000];
}