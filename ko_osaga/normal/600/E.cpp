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

struct occurence{
	map<int, int> mp;
	int cmx;
	lint cmxguy;
	void eat(occurence &occ){
		for(map<int, int> ::iterator it = occ.mp.begin(); it != occ.mp.end(); it++){
			pi i = *it;
			mp[i.first] += i.second;
			int val = mp[i.first];
			if(val == cmx){
				cmxguy += i.first;
			}
			else if(val > cmx){
				cmx = val;
				cmxguy = i.first;
			}
		}
	}
	void init(int c){
		cmx = 1;
		cmxguy = c;
		mp[c] = 1;
	}
}v[100005];

int n, c[100005];
vector<int> gph[100005];

lint ret[100005];
int size[100005];

int dfs(int x, int p){
	int pnt = x;
	v[x].init(c[x]);
	size[x] = 1;
	for(int ii=0; ii<gph[x].size(); ii++){ int i = gph[x][ii];
		if(i == p) continue;
		int tmp = dfs(i, x);
		if(size[i] > size[x]){
			v[tmp].eat(v[pnt]);
			pnt = tmp;
		}
		else{
			v[pnt].eat(v[tmp]);
		}
		size[x] += size[i];
	}
	ret[x] = v[pnt].cmxguy;
	return pnt;
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&c[i]);
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0);
	for(int i=1; i<=n; i++) printf("%lld ",ret[i]);
}