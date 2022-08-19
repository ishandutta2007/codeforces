#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
using pi = pair<int, int>;
const int MAXN = 200005;

int n, m, a, b, vv;
set<int> s1, s2;

vector<int> closest(set<int> &s, int l, int r){
	vector<int> ret;
	auto it = s.lower_bound(l);
	if(it != s.end()) ret.push_back(*it);
	if(it != s.begin()) ret.push_back(*prev(it));
	it = s.lower_bound(r);
	if(it != s.end()) ret.push_back(*it);
	if(it != s.begin()) ret.push_back(*prev(it));
	return ret;
}

int main(){
	scanf("%d %d %d %d %d",&n,&m,&a,&b,&vv);
	for(int i=0; i<a; i++){
		int x;
		scanf("%d",&x);
		s1.insert(x);
	}
	for(int i=0; i<b; i++){
		int x;
		scanf("%d",&x);
		s2.insert(x);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1 == x2){
			// what the fuck?
			printf("%d\n", abs(y2-y1));
			continue;
		}
		int ans = 1e9;
		if(s1.size()){
			vector<int> v = closest(s1, y1, y2);
			for(auto &i : v){
				ans = min(ans, abs(i - y1) + abs(i - y2) + abs(x1 - x2));
			}
		}
		if(s2.size()){
			vector<int> v = closest(s2, y1, y2);
			for(auto &i : v){
				ans = min(ans, abs(i - y1) + abs(i - y2) + (vv - 1 + abs(x1 - x2)) / vv);
			}
		}
		printf("%d\n", ans);
	}
}