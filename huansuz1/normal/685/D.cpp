#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

map<int, vector<pair<int, int> > > d;
map<int, vector<pair<int, int> > > :: iterator cr, pr;

multiset<pair<int, int> > st;
multiset<pair<int, int> > :: iterator cur, prv;
long long ans[100100];

int main() {

	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		d[y].push_back(make_pair(x, -1));
		d[y - k].push_back(make_pair(x, 1));
	}

	for(pr = d.begin(), cr = pr, cr++; cr != d.end(); pr = cr, cr++) {
		vector<pair<int, int> > &vc = pr -> second;
		for(int i = 0; i < (int)vc.size(); i++) {
			if(vc[i].second == 1) {
				st.insert(make_pair(vc[i].first - k, 1));
				st.insert(make_pair(vc[i].first, -1));
			} else {
				st.erase(st.find(make_pair(vc[i].first - k, 1)));
				st.erase(st.find(make_pair(vc[i].first, -1)));
			}
		}
		if(!st.empty()) {
			int bal = 0, len = cr -> first - pr -> first;
			for(prv = st.begin(), cur = prv, cur++; cur != st.end(); prv = cur, cur++) {
				bal += prv -> second;
				if(bal) ans[bal] += (cur -> first - prv -> first) * 1ll * len;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		printf("%lld ", ans[i]);
	}

	return 0;
}