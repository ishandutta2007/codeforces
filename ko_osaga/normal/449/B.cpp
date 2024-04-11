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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;

struct edg{
	lint dist;
	int pos, train;
	bool operator<(const edg &a)const{
		return pi(dist, train) > pi(a.dist, a.train);
	}
};

int n, m, q;
vector<edg> gph[100005];
bool vis[100005];

int main(){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0; i<m; i++){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		gph[s].push_back({x, e, 0});
		gph[e].push_back({x, s, 0});
	}
	for(int i=0; i<q; i++){
		int s, y;
		scanf("%d %d",&s,&y);
		gph[1].push_back({y, s, 1});
		gph[s].push_back({y, 1, 1});
	}
	int cnt = 0;
	priority_queue<edg> pq;
	pq.push({0, 1, 0});
	while(!pq.empty()){
		auto t = pq.top();
		pq.pop();
		if(vis[t.pos]) continue;
		vis[t.pos] = 1;
		if(t.train) cnt++;
		for(auto &i : gph[t.pos]){
			pq.push({i.dist + t.dist, i.pos, i.train});
		}
	}
	printf("%d",q-cnt);
}