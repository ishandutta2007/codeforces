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

set<int> s;
vector<int> v;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int v;
		scanf("%d",&v);
		s.insert(v);
	}
	for(auto &i : s) v.push_back(i);
	if(v.size() <= 2 || (v.size() == 3 && v[0] + v[2] == v[1] + v[1])){
		puts("YES");
	}
	else puts("NO");
}