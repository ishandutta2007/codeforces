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

int edpmax[300005];

int n, m, p[300005], a[3000005], b[300005];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		p[x] = i;
		edpmax[i] = n;
	}
	while(m--){
		int x, y;
		scanf("%d %d",&x,&y);
		x = p[x], y = p[y];
		if(x > y) swap(x, y);
		edpmax[x] = min(edpmax[x], y-1);
	}
	for(int i=n-1; i; i--){
		edpmax[i] = min(edpmax[i],edpmax[i+1]);
	}
	lint ret = 0;
	for(int i=1; i<=n; i++){
		ret += edpmax[i] - i + 1;
	}
	cout << ret;
}