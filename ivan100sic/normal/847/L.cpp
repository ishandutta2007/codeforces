#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> sus[1005];

list<set<int>> e[1005];
set<set<int>> orig[1005];
set<set<int>> gener[1005];
int br_sus[1005];
vector<int> suggested[1005];
int p[1005];

queue<int> q;

void vlada() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int sm = 0;
        while(sm < n - 1){
            int p;
            scanf("%d:", &p);
            vector<int> pom(p);
            for(int i = 0; i < p; i++){
                if(i == p - 1){
                    scanf("%d-", &pom[i]);
                } else scanf("%d,", &pom[i]);
            }
            sm += p;
            sus[i].push_back(pom);
        }
    }
}

vector<pair<int, int>> grane;
vector<int> ee[1005];
bool visited[1005];

void dfs(int x) {
	visited[x] = true;
	for (int y : ee[x]) {
		if (!visited[y]) {
			dfs(y);
		}
	}
}

void dfs2(int x, set<int>& s) {
	visited[x] = true;
	s.insert(x);

	for (int y : ee[x]) {
		if (!visited[y]) {
			dfs2(y, s);
		}
	}
}

bool is_tree() {

	if ((int)grane.size() != n-1) {
		return false;
	}

	for (auto p : grane) {
		ee[p.first].push_back(p.second);
		ee[p.second].push_back(p.first);
	}

	dfs(1);

	for (int i=1; i<=n; i++) {
		if (!visited[i]) {
			return false;
		}
	}

	for (int i=1; i<=n; i++) {
		fill(visited+1, visited+n+1, false);
		visited[i] = true;
		
		for (int y : ee[i]) {
			set<int> s;
			dfs2(y, s);
			gener[i].insert(move(s));
		}

		if (gener[i] != orig[i]) {
			cerr << "bad " << i << '\n';
			return false;
		}
	}

	return true;
}

int main() {

	// vlada
	vlada();

	for (int i=1; i<=n; i++) {
		for (auto& v : sus[i]) {
			e[i].push_back(set<int>(v.begin(), v.end()));
			orig[i].insert(set<int>(v.begin(), v.end()));
			br_sus[i]++;
		}
	}

	for (int i=1; i<=n; i++) {
		if (br_sus[i] == 1) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int x = q.front(); q.pop();

		e[x].clear();

		// obrisi x svuda
		for (int i=1; i<=n; i++) {

			for (auto it = e[i].begin(); it != e[i].end(); ) {

				if (it->count(x)) {
					it->erase(x);
					if (it->empty()) {
						grane.push_back({x, i});

						auto tmp = next(it);
						e[i].erase(it);
						it = tmp;

						br_sus[i]--;
						if (br_sus[i] == 1) {
							q.push(i);
						}
					} else {
						++it;
					}

				} else {
					++it;
				}
			}
		}		
	}

	if (!is_tree()) {
		printf("-1");
		return 0;
	}

	printf("%d\n", n-1);

	for (auto p : grane) {
		cout << p.first << ' ' << p.second << '\n';
	}
}