#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint n, x, k, sol;
llint l[MAXN];
multiset <llint> s, t;
map <llint, int> m;

int main () {
	cin >> n >> x >> k;
	for (int i=0; i<n; i++) {
		scanf("%I64d", &l[i]);
	}
	sort(l, l+n);
	for (int i=0; i<n; i++) {
		llint lim=l[i]/x*x-x*k;
		s.insert(l[i]);
		if (l[i]%x==0 && k==1 || l[i]%x!=0 && k==0) sol+=m[l[i]];
		m[l[i]]++;
		while (!s.empty()) {
			int val=*s.begin();
			if (val<=lim) {
				s.erase(s.begin());
			} else {
				break;
			}
		}
		t.insert(l[i]);
		while (!t.empty()) {
			int val=*t.begin();
			if (val<=lim+x) {
				t.erase(t.begin());
			} else {
				break;
			}
		}
		sol+=s.size()-t.size();
	}
	cout << sol;
	return 0;
}