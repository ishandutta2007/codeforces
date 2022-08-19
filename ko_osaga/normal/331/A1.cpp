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
typedef pair<int, int> pi;

int n;
lint a[300005], s[300005];
vector<pi> v;

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
		v.emplace_back(a[i], i);
		s[i] = s[i-1] + max(a[i], 0ll);
	}
	sort(v.begin(), v.end());
	lint ret = -1e18;
	int stp, edp;
	for(int i=0; i<v.size(); ){
		int e = i;
		while(e < v.size() && v[i].first == v[e].first) e++;
		if(e != i+1){
			if(ret < s[v[e-1].second-1] - s[v[i].second] + 2 * v[i].first){
				ret = max(ret, s[v[e-1].second-1] - s[v[i].second] + 2 * v[i].first);
				stp = v[i].second;
				edp = v[e-1].second;
			}
		}
		i = e;
	}
	vector<int> cnt;
	for(int i=1; i<stp; i++) cnt.push_back(i);
	for(int i=stp+1; i<edp; i++){
		if(a[i] < 0) cnt.push_back(i);
	}
	for(int i=edp+1; i<=n; i++) cnt.push_back(i);
	cout << ret << " " << cnt.size()<<endl;
	for(auto &i : cnt) printf("%d ",i);
}