#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 100005;

int n, m, sum;
int cnt[MAXN];
set<int> s[MAXN];
int p[MAXN];

vector<tuple<int, int, int>> dap;

void MOVE(int dst, int src, int v){
	vector<int> mutation;
	for(auto &i : s[dst]){
		if(s[src].find(i) == s[src].end()){
			continue;
		}
		s[src].erase(i);
		mutation.push_back(i);
	}
	while(v--){
		auto x = *s[src].begin();
		s[src].erase(x);
		s[dst].insert(x);
		dap.emplace_back(src + 1, dst + 1, x);
	}
	for(auto &i : mutation) s[src].insert(i);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++){
		int x; scanf("%d",&x);
		sum += x;
		p[i] = i;
		for(int j=0; j<x; j++){int v;
			scanf("%d",&v);
			s[i].insert(v);
		}
	}
	for(int i=0; i<sum; i++){
		cnt[n-1-i%n]++;
	}
	sort(p, p + n, [&](const int &a, const int &b){
		return s[a].size() < s[b].size();
	});
	int lx = -1, ly = 1e9;
	for(int i=0; i<n; i++){
		if(s[p[i]].size() < cnt[i]){
			lx = i;
		}
		if(s[p[i]].size() > cnt[i]) ly = min(ly, i);
	}
	if(lx == -1){
		puts("0");
		return 0;
	}
	while(true){
		while(lx >= 0 && s[p[lx]].size() == cnt[lx]) lx--;
		while(ly < n && s[p[ly]].size() == cnt[ly]) ly++;
		if(lx == -1) break;
		int thres0 = cnt[lx] - s[p[lx]].size();
		int thres1 = s[p[ly]].size() - cnt[ly];
		MOVE(p[lx], p[ly], min(thres0, thres1));
	}
	printf("%d\n", dap.size());
	for(auto &i : dap){
		int x, y, z; tie(x, y, z) = i;
		printf("%d %d %d\n", x, y, z);
	}
}