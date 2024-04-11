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

vector<int> gph[300005];
int n, m, k, s[300005], e[300005];

bool connected(){
	set<pi> edg;
	for(int i=0; i<m; i++){
		edg.insert(pi(s[i], e[i]));
		edg.insert(pi(e[i], s[i]));
	}
	set<int> s;
	queue<int> q;
	q.push(1);
	for(int i=2; i<=n; i++){
		s.insert(i);
	}
	while(!q.empty()){
		int t = q.front();
		q.pop();
		vector<int> stk;
		for(auto &i : s){
			if(edg.find(pi(t, i)) == edg.end()){
				stk.push_back(i);
			}
		}
		for(auto &i : stk){
			s.erase(i);
			q.push(i);
		}
	}
	if(s.size()) return 0;
	return 1;
}

int component(){
	set<pi> edg;
	for(int i=0; i<m; i++){
		if(s[i] == 1 || e[i] == 1) continue;
		edg.insert(pi(s[i], e[i]));
		edg.insert(pi(e[i], s[i]));
	}
	set<int> s;
	int cnt = 0;
	for(int i=2; i<=n; i++) s.insert(i);
	for(int i=2; i<=n; i++){
		if(s.find(i) != s.end()){
			cnt++;
			queue<int> q;
			q.push(i);
			s.erase(i);
			while(!q.empty()){
				int t = q.front();
				q.pop();
				vector<int> stk;
				for(auto &i : s){
					if(edg.find(pi(t, i)) == edg.end()){
						stk.push_back(i);
					}
				}
				for(auto &i : stk){
					s.erase(i);
					q.push(i);
				}
			}
		}
	}
	return cnt;
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0; i<m; i++){
		scanf("%d %d",&s[i], &e[i]);
	}
	if(!connected()){
		puts("impossible");
		return 0;
	}
	if(component() > k){
		puts("impossible");
		return 0;
	}
	set<int> notok;
	for(int i=0; i<m; i++){
		if(s[i] == 1 || e[i] == 1){
			notok.insert(s[i]);
			notok.insert(e[i]);
		}
	}
	notok.erase(1);
	if(n - 1 - notok.size() < k){
		puts("impossible");
		return 0;
	}
	puts("possible");
}