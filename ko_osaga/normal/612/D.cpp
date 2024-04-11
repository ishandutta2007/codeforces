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

map<int, int> mp;
int n, k;
vector<pi> v;

int nanuggy(int x){
	if(x > 0) return x/2;
	return (x-1)/2;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++){
		int s, e;
		scanf("%d %d",&s, &e);
		mp[2*s]++; mp[2*e+1]--;
	}
	int cnt = 0, prev = -1;
	for(auto &i : mp){
		int pcnt = cnt;
		cnt += i.second;
		if(pcnt >= k && cnt < k){
			v.emplace_back(nanuggy(prev), nanuggy(i.first));
		}
		if(pcnt < k && cnt >= k){
			prev = i.first;
		}
	}
	printf("%d\n",v.size());
	for(auto &i : v){
		printf("%d %d\n",i.first, i.second);
	}
}