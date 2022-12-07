#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int n, x, val[N];
set<pair<int, int> > s;
int ans[N];

int main() {
	scanf("%d", &n);
	scanf("%d", &x);
	val[1] = x;
	s.insert(make_pair(x, 1));
	for (int i = 2; i <= n; i++) { 
		scanf("%d", &x);
		val[i] = x;
		s.insert(make_pair(x, i));
		set<pair<int, int> >::iterator it = s.find(make_pair(x, i));
		set<pair<int, int> >::iterator it2 = it; it2++;
		if (it == s.begin()) {
			ans[i] = it2->second;
		} else if (it2 == s.end()) {
			it--;
			ans[i] = it->second;
		} else {
			it--;
			ans[i] = max(it->second, it2->second);
		}
	}
	for (int i = 2; i <= n; i++) printf("%d ", val[ans[i]]);
	return 0;
}