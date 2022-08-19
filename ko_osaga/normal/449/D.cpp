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

int cnt[1050000], ipow[1050000], bitcnt[1050000];
int n, a[1050000];

void dnc(int s, int e){
	if(s == e){
		cnt[s] += a[s];
		return;
	}
	int m = (s+e)/2;
	dnc(s, m);
	dnc(m+1, e);
	for(int i=s; i<=m; i++){
		cnt[i] += cnt[i+m+1-s];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int t;
		scanf("%d",&t);
		a[t]++;
	}
	ipow[0] = 1;
	for(int i=1; i<=(1<<20); i++){
		bitcnt[i] = bitcnt[i>>1] + (i&1);
		ipow[i] = (ipow[i-1] << 1) % mod;
	}
	dnc(0, (1<<20) - 1);
	lint ret = 0;
	for(int i=0; i<(1<<20); i++){
		if(bitcnt[i] & 1){
			ret += mod - ipow[cnt[i]];
		}
		else{
			ret += ipow[cnt[i]];
		}
		ret %= mod;
	}
	cout << ret;
}