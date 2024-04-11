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

int n, a[100005];
vector<pi> v;

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
}; 

vector<int> sfx, lcp;
int rev[100005], lg[100005];
int spt[17][100005];

int getlcp(int x, int y){
	x = rev[x], y = rev[y];
	if(x > y) swap(x, y);
	int l = lg[y-x];
	return min(spt[l][x], spt[l][y - (1<<l)]);
}

bool ok(int s, int e){
	if(2 * s < e) return 0;
	return getlcp(s - (e - s) + 1, s + 1) >= e - s;
}

vector<pi> ls[100005];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		lg[i] = lg[i-1];
		while((2 << lg[i]) <= i) lg[i]++;
	}
	for(int i=1; i<=n; i++){
		cin >> a[i];
		v.emplace_back(a[i], i);
	}
	SuffixArray<int> sa(a+1, a+n+1);
	sfx = sa.build();
	lcp = sa.lcparray();
	for(int i=0; i<n; i++){
		rev[sfx[i] + 1] = i;
		if(i < n-1) spt[0][i] = lcp[i];
	}
	for(int i=1; i<17; i++){
		for(int j=0; j<n-1; j++){
			spt[i][j] = spt[i-1][j];
			if(j + (1<<(i-1)) < n-1) spt[i][j] = min(spt[i-1][j], spt[i-1][j+ (1<<(i-1))]);
		}
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); ){
		int e = i;
		while(e < v.size() && v[e].first == v[i].first) e++;
		for(int j=i; j<e; j++){
			for(int k=j-1; k>=i; k--){
				if(ok(v[k].second, v[j].second)){
					ls[v[j].second - v[k].second].emplace_back(v[k].second, v[j].second);
					break;
				}
			}
		}
		i = e;
	}
	int ep = 0;
	for(int i=1; i<=n; i++){
		sort(ls[i].begin(), ls[i].end());
		for(auto &j : ls[i]){
			if(ep <= j.first - (j.second - j.first)){
				ep = j.first;
			}
		}
	}
	printf("%d\n",n - ep);
	for(int i=ep+1; i<=n; i++){
		printf("%d ",a[i]);
	}

}