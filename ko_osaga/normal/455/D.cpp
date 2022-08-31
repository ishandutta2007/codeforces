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
const int GS = 400;

int alert;

struct bucket{
	int elems[2 * GS + 5], sz;
	int cnt[100005];
	void clear(){
		while(sz){
			cnt[elems[--sz]]--;
		}
	}
	int get_size(){
		return sz;
	}
	int query(int s, int e, int x){
		if(s == 1 && e == sz) return cnt[x];
		return count(elems+s-1, elems+e, x);
	}
	void add(int pos, int val){
		cnt[val]++;
		pos--;
		for(int j=sz-1; j>=pos; j--){
			elems[j+1] = elems[j];
		}
		sz++;
		elems[pos] = val;
	}
	void del(int pos){
		pos--;
		cnt[elems[pos]]--;
		for(int j=pos; j<sz; j++){
			elems[j] = elems[j+1];
		}
		sz--;
	}
}bkt[255];

int n, a[100005];

void get_element(){
	int piv = 0;
	for(int i=0; i<250; i++){
		for(int j=0; j<bkt[i].sz; j++){
			a[piv++] = bkt[i].elems[j];
		}
	}
	alert = 0;
}

void init(){
	for(int i=0; i<250; i++){
		bkt[i].clear();
	}
	for(int i=0; i<n; i++){
		bkt[i/GS].add(i%GS + 1, a[i]);
	}
}

void add(int x, int v){
	for(int i=0; i<250; i++){
		if(x <= bkt[i].get_size()){
			bkt[i].add(x, v);
			if(bkt[i].get_size() >= 2 * GS){
				alert = 1;
			}
			return;
		}
		x -= bkt[i].get_size();
	}
}

int del(int x){
	for(int i=0; i<250; i++){
		if(x <= bkt[i].get_size()){
			int ret = bkt[i].elems[x-1];
			bkt[i].del(x);
			return ret;
		}
		x -= bkt[i].get_size();
	}
}

int query(int s, int e, int x){
	int u = 0, ret = 0;
	for(int i=0; i<250; i++){
		int st = u + 1, ed = u + bkt[i].get_size();
		st = max(st, s);
		ed = min(ed, e);
		if(st <= ed) ret += bkt[i].query(st - u, ed - u, x);
		u += bkt[i].get_size();
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	init();
	int q, lastans = 0;
	scanf("%d",&q);
	for(int i=0; i<q; i++){
		int t, l, r, k;
		scanf("%d",&t);
		if(t == 1){
			scanf("%d %d",&l,&r);
		}
		else{
			scanf("%d %d %d",&l,&r,&k);
		}
		l = (l + lastans - 1) % n + 1;
		r = (r + lastans - 1) % n + 1;
		k = (k + lastans - 1) % n + 1;
		if(l > r) swap(l, r);
		if(t == 1){
			int u = del(r);
			add(l, u);
		}
		else{
			lastans = query(l, r, k);
			printf("%d\n", lastans);
		}
		if(alert){
			get_element();
			init();
		}
	}
}