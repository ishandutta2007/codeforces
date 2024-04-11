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
typedef pair<double, double> pi;

int n, k;

struct line{
	int a, b, c;
}a[100005];

pi crs(line a, line b){
	double det = 1.0 * a.a * b.b - 1.0 * b.a * a.b;
	if(det == 0) return pi(-1e9, -1e9);
	return pi((1.0 * a.b * b.c - 1.0 * b.b * a.c) / det, (1.0 * a.c * b.a - 1.0 * a.a * b.c) / det);
}

int rrand(int s, int e){
	return rand() % (e - s + 1) + s;
}

int main(){
	srand(time(0));
	cin >> n >> k;
	for(int i=0; i<n; i++){
		scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
	}
	bool chk[100005] = {};
	vector<pair<int, int>> ret;
	int j = k;
	for(int i=0; i<100 && j; i++){
		vector<int> v;
		for(int l=0; l<n; l++){
			if(chk[l] == 0) v.push_back(l);
		}
		if(v.size() <= j){
			if(v.size()){
				ret.emplace_back(v[0], -2);
				chk[v[0]] = 1;
			}
		}
		else{
			int p = rrand(0, v.size() - 1);
			int q = rrand(0, v.size() - 2);
			if(p <= q) q++;
			auto t = crs(a[v[p]], a[v[q]]);
			int ok = 0;
			for(int i=0; i<n; i++){
				if(fabs(t.first * a[i].a + t.second * a[i].b + a[i].c) < 1e-8){
					ok++;
				}
			}
			if(ok * j >= count(chk, chk + n, false)){
				ret.emplace_back(v[p], v[q]);
				for(int i=0; i<n; i++){
					if(fabs(t.first * a[i].a + t.second * a[i].b + a[i].c) < 1e-8){
						chk[i] = 1;
					}
				}
				j--;
			}
		}
	}
	if(count(chk, chk + n, false)){
		puts("NO");
	}
	else{
		printf("YES\n%d\n",ret.size());
		for(auto &i : ret){
			printf("%d %d\n",i.first+1, i.second+1);
		}
	}
}