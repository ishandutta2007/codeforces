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

struct pt{
	int x, y, idx;
}a[1000005];

int n;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].x, &a[i].y);
		a[i].idx = i;
	}
	sort(a,a+n,[&](const pt &a, const pt &b){
		if(a.x / 1000 != b.x / 1000) return a.x < b.x;
		if((a.x / 1000) % 2 == 1) return a.y < b.y;
		return a.y > b.y;
	});
	for(int i=0; i<n; i++){
		printf("%d ",1 + a[i].idx);
	}
}