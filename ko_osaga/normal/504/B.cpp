#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
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

int n;

struct bit{
	int tree[200005];
	void add(int x, int v){
		while(x <= n){
			tree[x] += v;
			x += x & -x;
		}
	}
	int query(int x){
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
	int kth(int x){
		int p = 0;
		for(int i=18; i>=0; i--){
			if(p + (1<<i) <= n && tree[p + (1<<i)] < x){
				p += (1<<i);
				x -= tree[p];
			}
		}
		p++;
		return p;
	}
}bit1, bit2, bit3;

int p[200005], q[200005];
int up[200005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d",&p[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d",&q[i]);
	}
	for(int i=n-1; i>=0; i--){
		bit1.add(p[i]+1, 1);
		up[i] += bit1.query(p[i]);
	}
	for(int i=n-1; i>=0; i--){
		bit2.add(q[i] + 1, 1);
		up[i] += bit2.query(q[i]);
	}
	for(int i=n-1; i>=0; i--){
		if(i) up[i-1] += up[i] / (n - i);
		up[i] %= n - i;
	}
	for(int i=1; i<=n; i++) bit3.add(i, 1);
	for(int i=0; i<n; i++){
		int p = bit3.kth(up[i] + 1);
		printf("%d ", p-1);
		bit3.add(p, -1);
	}
}