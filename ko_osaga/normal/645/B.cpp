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

int n, k, a[100005];
int tree[100005];

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

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++) a[i] = i;
	for(int i=1; i<=k; i++){
		if(i < n + 1 - i) swap(a[i], a[n+1-i]);
	}
	lint ret = 0;
	for(int i=n; i; i--){
		ret += query(a[i]-1);
		add(a[i], 1);
	}
	cout << ret;
}