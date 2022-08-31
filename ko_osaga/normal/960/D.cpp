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
const int MAXN = 100005;

lint valShift[100];
lint ndShift[100];
lint pwr[100];

int geth(lint x){
	if(x == 1) return 0;
	return geth(x / 2) + 1;
}

int main(){
	int q;
	scanf("%d",&q);
	for(int i=0; i<61; i++) pwr[i] = (1ll << i);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t == 1){
			lint x, v;
			scanf("%lld %lld",&x,&v);
			int h = geth(x);
			v = -v;
			valShift[h] += v;
			valShift[h] %= pwr[h];
			valShift[h] += pwr[h];
			valShift[h] %= pwr[h];
		}
		if(t == 2){
			lint x, v;
			scanf("%lld %lld",&x,&v);
			int h = geth(x);
			v = -v;
			ndShift[h] += v;
			ndShift[h] %= pwr[h];
			ndShift[h] += pwr[h];
			ndShift[h] %= pwr[h];
		}
		if(t == 3){
			lint x;
			scanf("%lld",&x);
			int h = geth(x);
			x += pwr[h] - valShift[h];
			x %= pwr[h];
			x += pwr[h];
			vector<lint> ans;
			while(x){
				printf("%lld ", pwr[h] + (x + valShift[h]) % pwr[h]);
				x += pwr[h] - ndShift[h];
				x %= pwr[h];
				x = (pwr[h] + x) / 2;
				h--;
			}
			puts("");
		}
	}
}