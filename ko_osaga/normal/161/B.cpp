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

int n, k;
vector<pi> buck[2];
vector<vector<int>> sln;
int val[1005];

int main(){
	cin >> n >> k;
	lint ret = 0, minv = 1e9;
	for(int i=0; i<n; i++){
		int c, t;
		cin >> c >> t;
		val[i+1] = c;
		buck[t-1].push_back(pi(c, i+1));
		ret += c;
		minv = min(minv, 1ll * c);
	}
	for(int i=0; i<2; i++){
		sort(buck[i].begin(), buck[i].end());
	}
	lint tmp = 0;
	for(int i=0; i<min(k-1, (int)buck[0].size()); i++){
		tmp += buck[0][buck[0].size()-i-1].first;
	}
	if(k-1 < buck[0].size()){
		tmp += minv;
		for(int i=0; i<k-1; i++){
			vector<int> t;
			t.push_back(buck[0][buck[0].size()-1-i].second);
			sln.push_back(t);
		}
		vector<int> l;
		for(int i=0; i<buck[0].size()-k+1; i++){
			l.push_back(buck[0][i].second);
		}
		for(auto &i : buck[1]){
			l.push_back(i.second);
		}
		sln.push_back(l);
	}
	else{
		for(auto &i : buck[0]){
			vector<int> t;
			if(k){
				t.push_back(i.second);
				sln.push_back(t);
				k--;
			}
		}
		for(auto &i : buck[1]){
			vector<int> t;
			if(k){
				t.push_back(i.second);
				sln.push_back(t);
				k--;
			}
			else{
				sln[sln.size()-1].push_back(i.second);
			}
		}
		// use all
	}
	printf("%.1f\n",ret - tmp * 0.5);
	for(auto &i : sln){
		printf("%d ",i.size());
		for(auto &j : i){
			printf("%d ",j);
		}
		puts("");
	}
}