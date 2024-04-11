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

int n, p;
int c[4005], h[4005], t[4005];
vector<pi> elem[20005];

int *l[20005];
int *r[20005];
int vac[4005];
bool ok[20005];

void build(int s, int e){
	for(int i=s; i<=e; i++){
		if(elem[i].size()) ok[s/p] = 1;
	}
	if(!ok[s/p]) return;
	l[s] = (int*) calloc(4005, sizeof(int));
	r[e] = (int*) calloc(4005, sizeof(int));
	for(int i=s; i<=e; i++){
		if(i != s){
			if(elem[i].empty()){
				l[i] = l[i-1];
			}
			else{
				l[i] = (int*) calloc(4005, sizeof(int));
				for(int j=0; j<=4000; j++){
					l[i][j] = l[i-1][j];
				}
			}
		}
		for(auto &j : elem[i]){
			for(int k=4000; k>=j.first; k--){
				l[i][k] = max(l[i][k], l[i][k-j.first] + j.second);
			}
		}
	}
	for(int i=e; i>=s; i--){
		if(i != e){
			if(elem[i].empty()){
				r[i] = r[i+1];
			}
			else{
				r[i] = (int*) calloc(4005, sizeof(int));
				for(int j=0; j<=4000; j++){
					r[i][j] = r[i+1][j];
				}
			}
		}
		for(auto &j : elem[i]){
			for(int k=4000; k>=j.first; k--){
				r[i][k] = max(r[i][k], r[i][k-j.first] + j.second);
			}
		}
	}
	// l[i][j] = [Low, i]  knapsack
	// r[i][j] = [i, High - 1]  knapsack
}


int main(){
	cin >> n >> p;
	for(int i=0; i<n; i++){
		int c, h, t;
		cin >> c >> h >> t;
		elem[t].emplace_back(c, h);
	}
	for(int i=0; i+p-1<=20000; i+=p){
		build(i, i+p-1);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int a, b;
		scanf("%d %d",&a,&b);
		int dl = (a/p) * p;
		int *x, *y;
		if(max(a-p+1, 1) < dl && ok[max(a-p+1, 1)/p]) x = r[max(a-p+1, 1)];
		else x = vac;
		if(ok[a/p]) y = l[a];
		else y = vac;
		int ret = 0;
		for(int i=0; i<=b; i++){
			ret = max(ret, x[i] + y[b-i]);
		}
		printf("%d\n",ret);
	}
}