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

int n, m, x, y, a[100005], b[100005];

int main(){
	scanf("%d %d %d %d",&n,&m,&x,&y);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	vector<pi> v;
	int p = 1;
	for(int i=1; i<=m; i++){
		int b;
		scanf("%d",&b);
		while(p <= n && a[p] < b - y) p++;
		if(p <= n && a[p] <= b + x){
			v.emplace_back(p, i);
			p++;
		}
	}
	printf("%d\n",v.size());
	for(auto &i : v){
		printf("%d %d\n",i.first, i.second);
	}
}