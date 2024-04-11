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
typedef pair<int, int> pi;

int n, m, p, a[200005];
vector<int> elem[200005], pos[200005];

vector<int> ret;

void match(vector<int> &v, vector<int> &w){
	if(v.size() < m) return;
	map<int, int> cnt;
	for(int i=0; i<m; i++){
		cnt[a[i]]++;
		if(cnt[a[i]] == 0) cnt.erase(a[i]);
		cnt[v[i]]--;
		if(cnt[v[i]] == 0) cnt.erase(v[i]);
	}
	if(cnt.size() == 0) ret.push_back(w[0]);
	for(int i=m; i<v.size(); i++){
		cnt[v[i-m]]++;
		if(cnt[v[i-m]] == 0) cnt.erase(v[i-m]);
		cnt[v[i]]--;
		if(cnt[v[i]] == 0) cnt.erase(v[i]);
		if(cnt.size() == 0){
			ret.push_back(w[i-m+1]);
		}
	}
}

int main(){
	cin >> n >> m >> p;
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		elem[i%p].push_back(x);
		pos[i%p].push_back(i+1);
	}
	for(int i=0; i<m; i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; i<p; i++){
		match(elem[i], pos[i]);
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << endl;
	for(auto &i : ret){
		printf("%d ",i);
	}
}