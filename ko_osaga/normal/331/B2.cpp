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

int n, q, a[300005], r[300005];

struct bit{
	int tree[300005];
	void add(int x, int v){
		while(x <= n){
			tree[x] += v;
			x +=  x & -x;
		}
	}
	int sum(int x){
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit;



int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		r[a[i]] = i;
	}
	for(int i=1; i<n; i++){
		if(r[i] > r[i+1]) bit.add(i, 1);
	}
	scanf("%d",&q);
	while(q--){
		int p, x, y;
		scanf("%d %d %d",&p,&x,&y);
		if(p == 1){
			printf("%d\n",bit.sum(y-1) - bit.sum(x-1)+1);
		}
		else{
			set<int> s;
			if(r[a[x]-1] > r[a[x]] && a[x] > 1) s.insert(a[x]-1);
			if(r[a[x]] > r[a[x]+1] && a[x]+1 <= n) s.insert(a[x]);
			if(r[a[y]-1] > r[a[y]] && a[y] > 1) s.insert(a[y]-1);
			if(r[a[y]] > r[a[y]+1] && a[y]+1 <= n) s.insert(a[y]);
			for(auto &i : s){
				bit.add(i, -1);
			}
			s.clear();
			swap(a[x], a[y]);
			swap(r[a[x]], r[a[y]]);
			if(r[a[x]-1] > r[a[x]] && a[x] > 1) s.insert(a[x]-1);
			if(r[a[x]] > r[a[x]+1] && a[x]+1 <= n) s.insert(a[x]);
			if(r[a[y]-1] > r[a[y]] && a[y] > 1) s.insert(a[y]-1);
			if(r[a[y]] > r[a[y]+1] && a[y]+1 <= n) s.insert(a[y]);
			for(auto &i : s){
				bit.add(i, 1);
			}
			s.clear();
		}
	}
}