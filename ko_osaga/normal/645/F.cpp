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

int moe[1000005], low[1000005], dmoe[1000005];
lint fact[1000005], invf[1000005];

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

void init(){
	low[1] = moe[1] = 1;
	for(int i=2; i<=1000000; i++){
		for(int j=i; j<=1000000; j+=i){
			if(!low[j]) low[j] = i;
		}
	}
	for(int i=2; i<=1000000; i++){
		int cnt = 0, plow = -1;
		for(int j=i; j>1; j/=low[j]){
			if(plow == low[j]){
				cnt = -1;
				break;
			}
			plow = low[j];
			cnt++;
		}
		if(cnt >= 0){
			moe[i] = cnt%2 ? -1 : 1;
		}
	}
	for(int i=1; i<=1000000; i++){
		for(int j=i; j<=1000000; j+=i){
			dmoe[j] += i * moe[j/i];
		}
	}
	fact[0] = invf[0] = 1;
	for(int i=1; i<=1000000; i++){
		fact[i] = fact[i-1] * i % mod;
		invf[i] = ipow(fact[i], mod - 2);
	}
}

inline lint bino(int x, int y){
	if(x < y) return 0;
	return fact[x] * (invf[y] * invf[x-y] % mod) % mod;
}

int n, k, q, a[100005];
int divisor[1000005];
lint cnt[1000005], ret;

int main(){
	init();
	scanf("%d %d %d",&n,&k,&q);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		for(int j=1; j*j<=a[i]; j++){
			if(a[i] % j == 0){
				divisor[j]++;
				if(j * j != a[i]) divisor[a[i] / j]++;
			}
		}
	}
	for(int i=1; i<=1000000; i++){
		ret += 1ll * dmoe[i] * bino(divisor[i], k);
		ret %= mod;
	}
	while(q--){
		int a[1];
		scanf("%d",&a[0]);
		int i = 0;
		vector<int> yaksu;
		for(int j=1; j*j<=a[i]; j++){
			if(a[i] % j == 0){
				divisor[j]++;
				yaksu.push_back(j);
				if(j * j != a[i]){
					divisor[a[i] / j]++;
					yaksu.push_back(a[i] / j);
				}
			}
		}
		for(auto &i : yaksu){
			ret += 1ll * dmoe[i] * (bino(divisor[i], k) - bino(divisor[i]-1, k) + mod) % mod;
			ret %= mod;
		}
		printf("%lld\n",ret);
	}
}