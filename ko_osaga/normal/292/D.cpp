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

struct disj{
	int pa[505];
	void init(int n){
		for(int i=1; i<=n; i++){
			pa[i] = i;
		}
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

struct event{
	int time;
	int s, e;
}edg[10005];

vector<event> ledg, redg;
int n, m;

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int s, e;
		cin >> s >> e;
		edg[i] = {i+1, s, e};
	}
	disj.init(n);
	for(int i=0; i<m; i++){
		if(disj.uni(edg[i].s, edg[i].e)){
			ledg.push_back(edg[i]);
		}
	}
	disj.init(n);
	for(int i=m-1; i>=0; i--){
		if(disj.uni(edg[i].s, edg[i].e)){
			redg.push_back(edg[i]);
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=0; i<q; i++){
		int s, e;
		scanf("%d %d",&s, &e);
		disj.init(n);
		for(auto &i : ledg){
			if(i.time < s) disj.uni(i.s, i.e);
			else break;
		}
		for(auto &i : redg){
			if(i.time > e) disj.uni(i.s, i.e);
			else break;
		}
		int cnt = 1;
		for(int i=2; i<=n; i++){
			cnt += disj.uni(1, i);
		}
		printf("%d\n",cnt);
	}
}