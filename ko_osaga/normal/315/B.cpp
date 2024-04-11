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

int n, q, a[100005];
int full;

int main(){
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	while(q--){
		int t; scanf("%d",&t);
		if(t == 1){
			int i, v;
			scanf("%d %d",&i, &v);
			a[i] = v - full;
		}
		if(t == 2){
			int y; scanf("%d",&y);
			full += y;
		}
		if(t == 3){
			int x; scanf("%d",&x);
			printf("%d\n", full + a[x]);
		}
	}
}