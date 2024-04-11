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

int n, k, a[500005];
lint sum;

int up(){
	int tk = k;
	int cnt = 0;
	for(int i=1; i<n; i++){
		int dx = a[i] - a[i-1];
		if(1ll * dx * i <= tk){
			tk -= 1ll * dx * i;
		}
		else{
			int dv = a[i-1] + tk / i;
			return dv;
		}
	}
	return a[n-1];
}

int dn(){
	int tk = k;
	int cnt = 0;
	for(int i=n-1; i; i--){
		int dx = a[i] - a[i-1];
		if(1ll * dx * (n-i) <= tk){
			tk -= 1ll * dx * (n - i);
		}
		else{
			int dv = a[i] - tk / (n - i);
			return dv;
		}
	}
	return a[0];
}

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	sort(a, a+n);
	lint diff = 0;
	for(int i=0; i<n; i++){
		diff += max(a[n-i-1] - a[i], 0);
	}
	int p = up();
	int q = dn();
	int ret = q - p;
	if(sum % n) ret = max(ret, 1);
	else ret = max(ret, 0);
	printf("%d\n",ret);
}