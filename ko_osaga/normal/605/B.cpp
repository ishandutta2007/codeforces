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
#include <stdio.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m;
vector<pi> tree, xtree;
int s[100005], e[100005];

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int w, t;
		scanf("%d %d",&w, &t);
		if(t == 1){
			tree.emplace_back(w, i);
		}
		else{
			xtree.emplace_back(w, i);
		}
	}
	sort(tree.begin(), tree.end());
	sort(xtree.begin(), xtree.end());
	for(int i=1; i<n; i++){
		s[tree[i-1].second] = i;
		e[tree[i-1].second] = i+1;
	}
	int pt = 0;
	for(int i=3; i<=n; i++){
		for(int j=i-2; j>=1; j--){
			if(pt == xtree.size()) break;
			if(xtree[pt].first < tree[i-2].first){
				puts("-1");
				return 0;
			}
			s[xtree[pt].second] = j;
			e[xtree[pt].second] = i;
			pt++;
		}
		if(pt == xtree.size()) break;
	}
	for(int i=0; i<m; i++){
		printf("%d %d\n",s[i], e[i]);
	}
}