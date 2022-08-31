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

int n, a[100005];
lint codd[100005], sum[100005];
lint le[100005], ri[100005];

int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		scanf("%d",&a[i]);
		codd[i] = codd[i-1] + (a[i] % 2 == 0);
		sum[i] = sum[i-1] + a[i];
	}
	for(int i=1; i<n; i++){
		if(a[i] == 1){
			le[i] = sum[i];
		}
		else{
			le[i] = le[i-1] + (a[i] % 2);
		}
	}
	for(int i=n-1; i; i--){
		if(a[i] == 1){
			ri[i] = sum[n-1] - sum[i-1];
		}
		else{
			ri[i] = ri[i+1] + (a[i] % 2);
		}
	}
	lint ret = 1e18, cpnt = 1e18;
	for(int i=1; i<=n; i++){
		cpnt = min(cpnt, le[i-1] - codd[i-1]);
		ret = min(ret, ri[i] + codd[i-1] + cpnt);
	}
	ret = -ret;
	for(int i=1; i<n; i++) ret += a[i];
	cout << ret;
}