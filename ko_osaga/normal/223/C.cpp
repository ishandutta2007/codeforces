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
const int mod = 1e9 + 7;

int bino[1005][1005];
int n, k, a[2005];
int inv[2005];

lint ipow(int x, int p){
	lint ret = 1, piv = x;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret;
}

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	if(k == 0){
		for(int i=1; i<=n; i++){
			printf("%d ",a[i]);
		}
		return 0;
	}
	k--;
	inv[0] = 1;
	for(int i=1; i<=n; i++){
		inv[i] = ipow(i, mod - 2);
	}
	for(int i=1; i<=n; i++){
		int ret = 0;
		lint bino = 1;
		for(int j=i; j; j--){
			ret += 1ll * a[j] * bino % mod;
			ret %= mod;
			bino *= 1ll * (i - j + 1 + k) * inv[i-j+1] % mod;
			bino %= mod;
		}
		printf("%d ",ret);
	}
}