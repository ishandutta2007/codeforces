#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define x first
#define y second

const int N = 1505;

int n, a[N];
map<int, vector<pii>> v;
vector<pii> r;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", a + i);
		for(int j = i, s = 0; j >= 1; j--){
			s += a[j];
			v[s].emplace_back(j, i);
		}
	}
	for(auto &i : v){
		vector<pii> t;
		for(pii j : i.y){
			if(t.empty() || t.back().y < j.x) t.push_back(j);
		}
		if(r.size() < t.size()) r = t;
	}
	printf("%d\n", r.size());
	for(pii i : r) printf("%d %d\n", i.x, i.y);
}