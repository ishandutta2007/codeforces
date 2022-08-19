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
const int mod = 1e9 + 7;

int n, k;

vector<pi> v;

vector<int> hmerge(vector<int> &a, vector<int> &b){
	vector<int> c;
	for(auto &i : a) c.push_back(i);
	for(auto &i : b) c.push_back(i);
	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());
	while(c.size() > 11){
		c.pop_back();
	}
	return c;
}

vector<int> lmerge(vector<int> &a, vector<int> &b){
	vector<int> c;
	for(auto &i : a) c.push_back(i);
	for(auto &i : b) c.push_back(i);
	sort(c.begin(), c.end());
	while(c.size() > 11){
		c.pop_back();
	}
	return c;
}

vector<int> ret1, ret2;
struct seg{
	vector<int> ltree[530000], htree[530000];
	int lim;
	void init(int n, vector<pi> &a){
		for(lim = 1; lim <= n; lim <<= 1);
		for(int i=0; i<n; i++){
			int p = lim + i;
			ltree[p].push_back(a[i].second);
			htree[p].push_back(a[i].second);
		}
		for(int i=lim-1; i; i--){
			ltree[i] = lmerge(ltree[2*i], ltree[2*i+1]);
			htree[i] = hmerge(htree[2*i], htree[2*i+1]);
		}
	}
	void query(int s, int e){
		ret1.clear();
		ret2.clear();
		s += lim;
		e += lim;
		while(s < e){
			if(s%2 == 1){
				ret1 = lmerge(ret1, ltree[s]);
				ret2 = hmerge(ret2, htree[s]);
				s++;
			}
			if(e%2 == 0){
				ret1 = lmerge(ret1, ltree[e]);
				ret2 = hmerge(ret2, htree[e]);
				e--;
			}
			s >>= 1;
			e >>= 1;
		}
		if(s == e){				
			ret1 = lmerge(ret1, ltree[s]);
			ret2 = hmerge(ret2, htree[s]);
		}
	}
}seg;

int up(int x){
	return max(1,(x+1)/2);
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++){
		int x1, x2, y1, y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		x1 += x2;
		y1 += y2;
		v.push_back(pi(x1, y1));
	}
	lint ret = 5e18;
	sort(v.begin(), v.end());
	seg.init(n, v);
	for(int i=0; i<=k; i++){
		for(int j=max(i, n - k - 1); j<n; j++){
			if(j - i + 1 < n - k) continue;
			int tmp = 2e9;
			seg.query(i, j);
			int used = (j - i + 1) - (n - k);
			for(int k=0; k<=used; k++){
				for(int l=0; k+l<=used; l++){
					tmp = min(tmp, ret2[k] - ret1[l]);
				}
			}
			ret = min(ret, 1ll * up(v[j].first - v[i].first) * up(tmp));
		}
	}
	printf("%lld",ret);
}