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

int n, q;

struct bit{
	lint tree[1005][1005];
	void add(int x, int y, lint v){
		while(x <= n){
			for(int i=y; i<=n; i+=i&-i){
				tree[x][i] ^= v;
			}
			x += x & -x;
		}
	}
	lint query(int x, int y){
		lint ret = 0;
		while(x){
			for(int i=y; i; i-=i&-i){
				ret ^= tree[x][i];
			}
			x -= x & -x;
		}
		return ret;
	}
	lint rectquery(int sx, int sy, int ex, int ey){
		return query(ex, ey) ^ query(sx-1, ey) ^ query(ex, sy-1) ^ query(sx-1, sy-1);
	}
}bit1, bit2, bit3, bit4;

lint kxor(lint x, int p){
	if(p&1) return x;
	return 0;
}

lint query(int x, int y){
	if(x == 0 || y == 0) return 0;
	lint ret = 0;
	ret ^= bit1.rectquery(1, 1, x, y);
	ret ^= kxor(bit2.rectquery(x+1, 1, n, y), x);
	ret ^= kxor(bit3.rectquery(1, y+1, x, n), y);
	ret ^= kxor(bit4.rectquery(x+1, y+1, n, n), x * y);
	return ret;
}

void update(int x, int y, lint v){
	if(x == 0 || y == 0) return;
	bit4.add(x, y, v);
	bit3.add(x, y, kxor(v, x));
	bit2.add(x, y, kxor(v, y));
	bit1.add(x, y, kxor(v, x*y));
}

int main(){
	scanf("%d %d",&n,&q);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int sx, sy, ex, ey;
			scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
			lint ret = query(ex, ey) ^ query(sx-1, ey) ^ query(ex, sy-1) ^ query(sx-1, sy-1);
			printf("%lld\n",ret);
		}
		else{
			int sx, sy, ex, ey; lint v;
			scanf("%d %d %d %d %lld",&sx,&sy,&ex,&ey,&v);
			update(sx-1, sy-1, v);
			update(ex, sy-1, v);
			update(sx-1, ey, v);
			update(ex, ey, v);
		}
	}
}