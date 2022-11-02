#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int n, q, a[200005], s[200005], e[200005];

vector<int> swp[200005], ans;

set<int> b;

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++) {
		s[i] = inf;
		e[i] = -inf;
	}
	int I = -1;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(a[i] == 0 || a[i] == q) I = i;
		if(a[i]) {
			s[a[i]] = min(s[a[i]], i);
			e[a[i]] = max(e[a[i]], i);
		}
	}
	if(I == -1) {
		puts("NO");
		return 0;
	}
	for(int i=1;i<=q;i++) {
		if(s[i] == inf) {
			s[i] = I;
			e[i] = I;
		}
		swp[s[i]].push_back(i);
		swp[e[i]+1].push_back(-i);
	}
	for(int i=1;i<=n;i++) {
		for(auto &T : swp[i]) {
			if(T > 0) b.insert(T);
			else b.erase(-T);
		}
		if(b.empty()) {
			ans.push_back(1);
		}
		else {
			auto it = b.end();
			it--;
			ans.push_back(*it);
		}
	}
	for(int i=1;i<=n;i++) {
		if(a[i] && a[i] != ans[i-1]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(auto &T : ans) {
		printf("%d ",T);
	}
}