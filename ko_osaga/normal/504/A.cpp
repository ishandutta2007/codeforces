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

queue<int> que;
vector<pi> ret;
int n, sm[100000], d[100005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> d[i] >> sm[i];
		if(d[i] == 1) que.push(i);
	}
	while(!que.empty()){
		int x = que.front(); que.pop();
		if(d[x] == 0) continue;
		ret.push_back({x, sm[x]});
		int p = sm[x];
		sm[p] ^= x;
		d[p]--;
		d[x]--;
		if(d[p] == 1) que.push(p);
	}
	printf("%d\n",ret.size());
	for(auto &i : ret){
		printf("%d %d\n",i.first, i.second);
	}
}