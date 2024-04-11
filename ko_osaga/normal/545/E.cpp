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
typedef pair<double, int> pi;

struct edg{
	int pos;
	lint cst;
	int idx;
	bool operator>(const edg &e)const{
		return cst > e.cst;
	}
};

vector<edg> gph[300005];
priority_queue<edg, vector<edg>, greater<edg> > pq;

lint dist[300005];
int n, m, s;
int pe[300005], pei[300005];

int main(){
	cin >> n >> m;
	for(int i=1; i<=m; i++){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		gph[s].push_back({e, x, i});
		gph[e].push_back({s, x, i});
	}
	memset(dist, 0x3f, sizeof(dist));
	cin >> s;
	pq.push({s, 0, -1});
	dist[s] = 0;
	while(!pq.empty()){
		auto t = pq.top();
		pq.pop();
		if(dist[t.pos] < t.cst) continue;
		for(auto &i : gph[t.pos]){
			if(dist[i.pos] > t.cst + i.cst){
				dist[i.pos] = t.cst + i.cst;
				pe[i.pos] = i.cst;
				pei[i.pos] = i.idx;
				pq.push({i.pos, dist[i.pos], -1});
			}
			else if(dist[i.pos] == t.cst + i.cst && pe[i.pos] > i.cst){
				pe[i.pos] = i.cst;
				pei[i.pos] = i.idx;
			}
		}
	}
	set<int> st;
	lint ret = 0;
	for(int i=1; i<=n; i++){
		if(i == s) continue;
		st.insert(pei[i]);
		ret += pe[i];
	}
	cout << ret << endl;
	for(auto &i : st) printf("%d ",i);
}