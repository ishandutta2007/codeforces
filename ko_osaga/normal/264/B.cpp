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

int low[100005], n, a[100005], dp[100005];

int main(){
	cin >> n;
	low[1] = 1;
	for(int i=2; i<=100000; i++){
		for(int j=i; j<=100000; j+=i){
			if(!low[j]) low[j] = i;
		}
	}
	for(int i=0; i<n; i++) cin >> a[i];
	int ret = 0;
	for(int i=0; i<n; i++){
		int v = 0;
		for(int j=a[i]; j>1; j/=low[j]){
			v = max(v, dp[low[j]]);
		}
		v++;
		for(int j=a[i]; j>1; j/=low[j]){
			dp[low[j]] = max(dp[low[j]], v);
		}
		ret = max(ret, v);
	}
	cout<<ret;
}