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

int n, m;
int cntx[4005], cnty[4005];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int t;
			scanf("%d",&t);
			cntx[4*i+2] += t;
			cnty[4*j+2] += t;
		}
	}
	lint p1 = 1e18, p2 = 1e18, px, py;
	for(int i=0; i<=4*n; i+=4){
		lint ret = 0;
		for(int j=2; j<4*n; j+=4){
			ret += 1ll * cntx[j] * (i - j) * (i - j);
		}
		if(p1 > ret){
			p1 = ret;
			px = i/4;
		}
	}
	for(int i=0; i<=4*m; i+=4){
		lint ret = 0;
		for(int j=2; j<4*m; j+=4){
			ret += 1ll * cnty[j] * (i - j) * (i - j);
		}
		if(p2 > ret){
			p2 = ret;
			py = i/4;
		}
	}
	printf("%lld\n%lld %lld",p1 + p2, px, py);
}