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

template<typename Ty>
struct SuffixArray
{
  vector<Ty> in;
  vector<int> out;
  template<typename Pt>
  SuffixArray(Pt begin, Pt end) : in(begin, end) {}
 
  vector<int> build() {
	int n = (int)in.size(), c = 0;
	vector<int> temp(n), pos2bckt(n), bckt(n), bpos(n);
	out.resize(n);
	for (int i = 0; i < n; i++) out[i] = i;
	sort(out.begin(), out.end(), [&](int a,int b) { return in[a] < in[b];});
	for(int i = 0; i < n; i++) { bckt[i] = c; if (i+1 == n || in[out[i]] != in[out[i+1]]) c++; }
	for(int h = 1; h < n && c < n; h <<= 1) {
	  for (int i = 0; i < n; i++) pos2bckt[out[i]] = bckt[i];
	  for (int i = n-1; i>=0; i--) bpos[bckt[i]] = i;
	  for (int i = 0; i < n; i++) if (out[i] >= n-h) temp[bpos[bckt[i]]++] = out[i];
	  for (int i = 0; i < n; i++) if (out[i] >= h) temp[bpos[pos2bckt[out[i]-h]]++] = out[i]-h;
	  c = 0;
	  for (int i = 0; i < n; i++) {
		int a = (i+1 == n) || (bckt[i] != bckt[i+1]) || (temp[i] >= n-h) || pos2bckt[temp[i+1]+h] != pos2bckt[temp[i]+h];
		bckt[i] = c;
		c += a;
	  }
	  temp.swap(out);
	}
	return out;
  }
 
  vector<int> lcparray() {
	if (in.size() != out.size()) build();
	int n = (int)in.size();
	vector<int> rank(n); // temporary
	vector<int> height(n-1); // output lcp array
 
	for(int i = 0; i < n; i ++) rank[out[i]] = i;
	int h = 0;
	for(int i = 0; i < n; i ++) {
	  if(rank[i] == 0) continue;
	  int j = out[rank[i]-1];
	  while(i+h < n && j+h < n && in[i+h] == in[j+h]) h++;
	  height[rank[i]-1] = h;
	  if(h > 0) h--;
	}
	return height;
  }
}; // thanks to kcm1700
 
int n;
char str[500005];
int dep[500005], howfar[500005]; // longest match
vector<pi> deps;

vector<int> sfx, lcp;

int main(){
	cin >> n;
	scanf("%s",str + 1);
	stack<int> stk;
	int ch = 0;
	for(int i=1; i<=n; i++){
		if(str[i] == '('){
			dep[i] = ++ch; 
		}
		else{
			dep[i] = --ch;
		}
	}
	for(int i=0; i<=n; i++){
		deps.push_back(pi(dep[i], i));
	}
	sort(deps.begin(), deps.end());
	for(int i=0; i<n; i++){
		auto t = lower_bound(deps.begin(), deps.end(), pi(dep[i] - 1, i));
		if(t->first != dep[i] - 1){
			howfar[i+1] = n;
		}
		else{
			howfar[i+1] = t->second - 1;
		}
	}
	for(int i=1; i<=n; i++){
	//	printf("[%d, %d]\n",i, howfar[i]);
	}
	// [i, howfar[i]]  .
	lint ret = 0; 
	for(int i=1; i<=n; i++){
		auto t = upper_bound(deps.begin(), deps.end(), pi(dep[i-1], howfar[i]));
		auto u = lower_bound(deps.begin(), deps.end(), pi(dep[i-1], i));
		ret += (t - u);
		//printf("%lld\n",ret);
	}
	SuffixArray<char> sa(str + 1, str + 1 + n);
	sfx = sa.build();
	lcp = sa.lcparray();
	for(int i=0; i<lcp.size(); i++){
		int p = sfx[i+1] + 1;
		int ep = min(howfar[p], p + lcp[i] - 1);
		auto t = upper_bound(deps.begin(), deps.end(), pi(dep[p-1], ep));
		auto u = lower_bound(deps.begin(), deps.end(), pi(dep[p-1], p));
		if(t > u) ret -= (t - u);
		//printf("%d %d %d %lld\n",sfx[i], sfx[i+1], lcp[i], ret);
	}
	printf("%lld\n", ret);
	return 0;
}