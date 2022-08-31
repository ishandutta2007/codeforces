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
const int B = 300;

int n, q, a[100005];
int nxt[100005], nxtd[100005], lst[100005];

void construct(int s, int e){
	for(int i=e; i>=s; i--){
		nxt[i] = i + a[i];
		lst[i] = i;
		nxtd[i] = 1;
		if(nxt[i] < e+1){
			nxtd[i] = nxtd[nxt[i]] + 1;
			lst[i] = lst[nxt[i]];
			nxt[i] = nxt[nxt[i]];
		}
	}
}

void query(int x){
	int ret = 0, rlst = 0;
	while(x <= n){
		rlst = lst[x];
		ret += nxtd[x];
		x = nxt[x];
	}
	printf("%d %d\n",rlst, ret);
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i+=B){
		construct(i, min(n, i+B-1));
	}
	while(q--){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int x;
			scanf("%d",&x);
			query(x);
		}
		else{
			int p, q;
			scanf("%d %d",&p, &q);
			a[p] = q;
			int l = ((p-1)/B) * B;
			construct(l + 1, min(n, l + B));
		}
	}
}