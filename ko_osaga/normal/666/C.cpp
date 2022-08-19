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

string s;
lint fact[100005], invf[100005];
lint ipow[100005];

lint c(int x, int y){
	return fact[x] * (invf[y] * invf[x-y] % mod) % mod;
}

lint p(int x){
	return ipow[x];
}

struct query{
	int x, y, idx;
};

vector<query> q;
int ret[100005];

lint fpow(int x, int y){
	lint ret = 1, piv = x;
	while(y){
		if(y&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		y >>= 1;
	}
	return ret;
}

int solve(int x, int y){
	if(y < x/2){
		lint ret = mod - fpow(26, x);
		for(int i=x; i>x-y; i--){
			ret += c(x, i) * ipow[i];
			ret %= mod;
		}
		return (mod - ret) % mod;
	}
	lint ret = 0;
	for(int i=0; i<=x-y; i++){
		ret += c(x, i) * ipow[i];
		ret %= mod;
	}
	return ret;
}
int main(){
	fact[0] = invf[0] = ipow[0] = 1;
	for(int i=1; i<=100000; i++){
		fact[i] = fact[i-1] * i % mod;
		ipow[i] = ipow[i-1] * 25 % mod;
		invf[i] = fpow(fact[i], mod - 2);
	}
	int Q;
	cin >> Q >> s;
	int piv = 0;
	while(Q--){
		int t;
		scanf("%d",&t);
		if(t == 1){
			string ts; 
			cin >> ts;
			s = ts;
		}
		else{
			int x;
			scanf("%d",&x);
			printf("%d\n", solve(x, (int)s.size()));
		}
	}
}