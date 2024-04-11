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
typedef pair<lint, lint> pi;

int n;
vector<int> gph[100005];
lint dp[100005][4];
int a[100005];

lint f(int x, int y, int p){
	if(~dp[x][y]) return dp[x][y];
	if(y == 0){
		lint ret = 0;
		for(auto &i : gph[x]){
			if(i == p) continue;
			ret = max(ret, f(i, 0, x));
		}
		return dp[x][y] = ret + a[x];
	}
	if(y == 1){
		lint ret = a[x];
		vector<lint> maxv;
		for(auto &i : gph[x]){
			if(i == p) continue;
			maxv.push_back(f(i, 0, x));
			ret = max(ret, f(i, 1, x));
		}
		sort(maxv.begin(), maxv.end());
		reverse(maxv.begin(), maxv.end());
		if(maxv.size() == 1){
			ret = max(ret, maxv[0] + a[x]);
		}
		if(maxv.size() >= 2){
			ret = max(ret, maxv[0] + maxv[1] + a[x]);
		}
		return dp[x][y] = ret;
	}
	if(y == 2){
		lint ret = 0;
		vector<lint> p1, p2;
		for(auto &i : gph[x]){
			if(i == p) continue;
			p1.push_back(f(i, 0, x) + a[x]);
			p2.push_back(f(i, 1, x));
			ret = max(ret, f(i, 1, x) + a[x]);
			ret = max(ret, f(i, 2, x) + a[x]);
		}
		lint tmp = -1e18;
		for(int i=0; i<p1.size(); i++){
			ret = max(ret, tmp + p2[i]);
			tmp = max(tmp, p1[i]);
		}
		tmp = -1e18;
		for(int i=p1.size()-1; i>=0; i--){
			ret = max(ret, tmp + p2[i]);
			tmp = max(tmp, p1[i]);
		}
		return dp[x][y] = ret;
	}
	if(y == 3){
		lint ret = 0;
		vector<pi> p1, p2, p3;
		for(auto &i : gph[x]){
			if(i == p) continue;
			p1.emplace_back(f(i, 0, x), i);
			p2.emplace_back(f(i, 1, x), i);
			p3.emplace_back(f(i, 2, x), i);
			ret = max(ret, f(i, 2, x) + a[x]);
			ret = max(ret, f(i, 3, x));
		}
		sort(p1.begin(), p1.end());
		sort(p2.begin(), p2.end());
		sort(p3.begin(), p3.end());
		reverse(p1.begin(), p1.end());
		reverse(p2.begin(), p2.end());
		reverse(p3.begin(), p3.end());
		while(p1.size() > 3) p1.pop_back();
		while(p2.size() > 3) p2.pop_back();
		while(p3.size() > 3) p3.pop_back();
		// just one full tree
		if(p2.size() >= 1){
			ret = max(ret, p2[0].first + a[x]);
		}
		// one disjoint path + one full tree
		if(p2.size() >= 2){
			for(auto &i : p1){
				for(auto &j : p2){
					if(i.second != j.second){
						ret = max(ret, i.first + j.first + a[x]);
					}
				}
			}
		}
		// two disjoint path + one full tree
		for(auto &i : p1){
			for(auto &j : p1){
				if(i == j) break;
				for(auto &k : p2){
					if(i.second != k.second && j.second != k.second){
						ret = max(ret, i.first + j.first + k.first + a[x]);
					}
				}
			}
		}
		// two disjoint tree
		if(p2.size() >= 2){
			ret = max(ret, p2[0].first + p2[1].first);
		}
		// one ups + one disjoint path
		for(auto &i : p1){
			for(auto &j : p3){
				if(i.second != j.second){
					ret = max(ret, i.first + j.first + a[x]);
				}
			}
		}
		return dp[x][y] = ret;
	}
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	lint ret = 0;
	for(int i=0; i<=3; i++){
		ret = max(ret, f(1, i, -1));
	}
	cout << ret;
}