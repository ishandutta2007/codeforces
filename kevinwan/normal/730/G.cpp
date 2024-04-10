#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
set<pair<int, int>> s;
void go(int a, int b) {
	s.insert({ a,b });
	printf("%d %d\n", a, b);
}
int mn =2e9;
int main() {
	int n,i,a,b;
	set<pair<int, int>>::iterator it;
	s.insert({ 0,0 });
	s.insert({ mn,mn });
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		it = --s.lower_bound({ a + b,0 });
		if ((*it).second < a) { go(a, a + b - 1); continue; }
		vector<int> sp;
		for (it = s.begin(); it != s.end(); it++) {
			sp.push_back((*it).first);
			sp.push_back((*it).second);
		}
		int j;
		for (j = 1; j + 1 < sp.size(); j += 2) {
			if (sp[j + 1] - sp[j] - 1 >= b) { go(sp[j] + 1, sp[j] + b); break; }
		}
	}
}