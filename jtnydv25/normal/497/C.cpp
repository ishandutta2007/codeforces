#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int N = 100005;
int n, m;
int k[N], assign[N];

int main() {
	vector<pair<pii,int>> parts;
	scanf("%d", &n);
	for (int i=1, a, b; i<=n; i++) {
		scanf("%d%d", &a, &b);
		parts.push_back({{a,b}, i});
	}
	sort(parts.begin(), parts.end());
	vector<pair<pii,int>> actors;
	scanf("%d", &m);
	for (int i=1, c, d; i<=m; i++) {
		scanf("%d%d%d", &c, &d, k+i);
		actors.push_back({{c,d}, i});
	}
	sort(actors.begin(), actors.end());
	int i = 0;
	set<pii> posActors;
	for (auto part : parts) {
		while (i < m && actors[i].F.F <= part.F.F) {
			posActors.insert({actors[i].F.S, actors[i].S});
			i++;
		}
		auto actor_it = posActors.lower_bound(make_pair(part.F.S, -1));
		if (actor_it != posActors.end()) {
			assign[part.S] = actor_it->S;
			k[actor_it->S]--;
			if (k[actor_it->S] == 0) {
				posActors.erase(actor_it);
			}
		}
		else {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (int i=1; i<=n; i++) {
		printf("%d%c", assign[i], " \n"[i==n]);
	}

	return 0;
}