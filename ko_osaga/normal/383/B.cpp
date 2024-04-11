#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <chrono>
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

int n, m;
bool low(pi x){
	return x.second == 1 || x.first == n;
}

bool high(pi x){
	return x.first == 1 || x.second == n;
}

bool cmp(pi x, pi y){
	return pi(x.second, x.first) < pi(y.second, y.first);
}

pi pnt[100005], qnt[100005];
bool vis[100005];

queue<int> que;

int seek(int x, int y){
	int t = lower_bound(pnt, pnt + m, pi(x, y)) - pnt;
	if(t == m) return -1;
	if(pnt[t] != pi(x, y)) return -1;
	return t;
}

int lowseek(int x, int y){
	int t = upper_bound(pnt, pnt + m, pi(x, y)) - pnt - 1;
	if(t == -1) return -1;
	if(pnt[t].first != x) return -1;
	return t;
}

int highseek(int x, int y){
	int tt = lower_bound(qnt, qnt + m, pi(x, y), cmp) - qnt;
	if(tt == m) return -1;
	int t = lower_bound(pnt, pnt + m, qnt[tt]) - pnt;
	if(pnt[t].second != y) return -1;
	return t;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		scanf("%d",&pnt[i].first);
		scanf("%d",&pnt[i].second);
		qnt[i] = pnt[i];
	}
	sort(pnt, pnt + m);
	sort(qnt, qnt + m, cmp);
	for(int i=0; i<m; i++){
		if(low(pnt[i])){
			vis[i] = 1;
			que.push(i);
		}
	}
	while(!que.empty()){
		int x = que.front();
		que.pop();
		if(high(pnt[x])){
			puts("-1");
			return 0;
		}
		for(int i=-1; i<=1; i++){
			for(int j=-1; j<=1; j++){
				if(i == 0 && j == 0) continue;
				int p = seek(pnt[x].first + i, pnt[x].second + j);
				if(p == -1) continue;
				if(vis[p]) continue;
				vis[p] = 1;
				que.push(p);
			}
		}
		int p = lowseek(pnt[x].first, pnt[x].second - 1);
		int q = lowseek(pnt[x].first - 1, pnt[x].second - 1);
		if(p != -1 && !vis[p]){
			vis[p] = 1;
			que.push(p);
		}
		if(q != -1 && !vis[q]){
			vis[q] = 1;
			que.push(q);
		}
		p = highseek(pnt[x].first + 1, pnt[x].second + 1);
		q = highseek(pnt[x].first + 1, pnt[x].second);
		if(p != -1 && !vis[p]){
			vis[p] = 1;
			que.push(p);
		}
		if(q != -1 && !vis[q]){
			vis[q] = 1;
			que.push(q);
		}
	}
	printf("%d",2*n-2);
}