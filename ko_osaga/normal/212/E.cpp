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
const int mod = 1e9 + 7;

int size[5005];
bool tmp[5005], ret[5005];
vector<int> gph[5005];
int n;

void dfs(int x, int p){
	size[x] = 1;
	vector<int> v;
	for(auto &i : gph[x]){
		if(i == p) continue;
		dfs(i, x);
		v.push_back(size[i]);
		size[x] += size[i];
	}
	v.push_back(n - size[x]);
	memset(tmp, 0, sizeof(tmp));
	tmp[0] = 1;
	for(auto &i : v){
		for(int j=n; j>=i; j--){
			tmp[j] |= tmp[j-i];
		}
	}
	for(int i=0; i<=n; i++){
		ret[i] |= tmp[i];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0);
	vector<int> t;
	for(int i=1; i<n-1; i++){
		if(ret[i]) t.push_back(i);
	}
	printf("%d\n",t.size());
	for(auto &i : t){
		printf("%d %d\n",i, n-1-i);
	}
}