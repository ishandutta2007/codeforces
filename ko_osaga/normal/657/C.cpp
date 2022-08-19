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

int n, k, b, c;
int a[200005];

int md(int x){
	return (x%5 + 5) % 5;
}

lint cost(int x){
	return 1ll * c * (x%5) + 1ll * b * (x/5);
}

int cnt1[5];
lint cnt2[5];

void add(int x){
	int md = (x % 5 + 5)%5;
	x -= md;
	cnt1[md]++;
	cnt2[md] += x / 5;
}

void del(int x){
	int md = (x % 5 + 5)%5;
	x -= md;
	cnt1[md]--;
	cnt2[md] -= x / 5;
}

lint query(int x){
	int md = (x % 5 + 5)%5;
	lint ret = 0;
	for(int i=0; i<5; i++){
		ret += 1ll * c * cnt1[i] * ((md - i + 5) % 5); 
	}
	x -= md;
	for(int i=0; i<5; i++){
		if(i <= md){
			ret += 1ll * b * (1ll * cnt1[i] * (x / 5) - cnt2[i]);
		}
		else{
			ret += 1ll * b * (1ll * cnt1[i] * (x / 5 - 1) - cnt2[i]);
		}
	}
	return ret;
}

deque<int> ls[5];

lint solve(int m){
	for(int i=0; i<5; i++){
		ls[i].clear();
		cnt1[i] = cnt2[i] = 0;
	}
	int cnt = 0;
	for(int i=0; i<k-1; i++){
		ls[md(a[i])].push_back(a[i]);
		add(a[i]);
		cnt++;
	}
	lint tret = 1e18;
	for(int i=k-1; i<n; i++){
		ls[md(a[i])].push_back(a[i]);
		cnt++;
		add(a[i]);
		int tt = a[i];
		while(md(tt) != m) tt++;
		while(cnt > k){
			lint maxcost = -1e18;
			int maxcostmd = -1;
			for(int i=0; i<5; i++){
				if(ls[i].empty()) continue;
				lint t = cost(tt - ls[i][0]);
				if(maxcost < t){
					maxcost = t;
					maxcostmd = i;
				}
			}
			del(ls[maxcostmd][0]);
			ls[maxcostmd].pop_front();
			cnt--;
		}
		tret = min(tret, query(tt));
	}
	return tret;
}

int main(){
	scanf("%d %d %d %d",&n,&k,&b,&c);
	if(b > 5 * c){
		b = 5 * c;
	}
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a, a+n);
	lint tret = 1e18;
	for(int i=0; i<5; i++){
		tret = min(tret, solve(i));
	}
	cout << tret;
}