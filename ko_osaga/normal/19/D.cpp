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

int n;
int q[200005], x[200005], y[200005];
vector<int> vy;

struct seg{
	set<pi> tree[200005]; // x min, otherwise y min

	void add(int x, int y){
		int oy = y;
		y = lower_bound(vy.begin(), vy.end(), y) - vy.begin() + 1;
		while(y <= vy.size()){
			tree[y].insert(pi(x, -oy));
			y += y & -y;
		}
	}
	void del(int x, int y){
		int oy = y;
		y = lower_bound(vy.begin(), vy.end(), y) - vy.begin() + 1;
		while(y <= vy.size()){
			tree[y].erase(pi(x, -oy));
			y += y & -y;
		}
	}
	pi query(int x, int y){
		int oy = y;
		y = lower_bound(vy.begin(), vy.end(), y) - vy.begin() + 1;
		pi ret(2e9, 2e9);
		while(y){
			auto t = tree[y].lower_bound(pi(x, -2e9));
			if(t != tree[y].end()) ret = min(ret, *t);
			y -= y & -y;
		}
		return ret;
	}
}seg;

char buf[20];
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%s %d %d",buf, &x[i], &y[i]);
		if(*buf == 'a') q[i] = 1;
		if(*buf == 'r') q[i] = 2;
		if(*buf == 'f') q[i] = 3, x[i]++, y[i]++;
		y[i] = -y[i];
		vy.push_back(y[i]);
	}
	sort(vy.begin(), vy.end());
	vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
	for(int i=0; i<n; i++){
		if(q[i] == 1){
			seg.add(x[i], y[i]);
		}
		if(q[i] == 2){
			seg.del(x[i], y[i]);
		}
		if(q[i] == 3){
			pi t = seg.query(x[i], y[i]);
			if(t.first > 1e9) puts("-1");
			else printf("%d %d\n",t.first, t.second);
		}
	}
}