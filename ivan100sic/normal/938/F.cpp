#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, g, h;
string s;

struct stanje {
	int pos, maska;
};

bool vis[5005][5005];
bool vist[5005][5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	h = 1;
	g = 0;
	while (2*h <= n) {
		h <<= 1;
		g++;
	}

	int cn = n - (h - 1);

	vector<stanje> curr;
	string sol;

	curr.push_back({0, 0});

	for (int i=0; i<cn; i++) {

		queue<stanje> q;
		vector<stanje> terminal[26];

		for (auto st : curr)
			q.push(st);

		while (!q.empty()) {
			auto st = q.front(); q.pop();
			// uzmi terminalni simbol?
			if (st.pos < n && !vist[st.pos + 1][st.maska]) {
				int y = s[st.pos] - 'a';
				terminal[y].push_back({st.pos + 1, st.maska});
				vist[st.pos + 1][st.maska] = 1;
			}
			// ne
			for (int i=0; i<g; i++) {
				int pos2 = st.pos + (1 << i);
				int maska2 = st.maska | (1 << i);
				if (pos2 <= n && maska2 != st.maska && !vis[pos2][maska2]) {
					q.push({pos2, maska2});
					vis[pos2][maska2] = 1;
				}
			}
		}

		for (int i=0; i<26; i++) {
			if (terminal[i].size()) {
				sol += (char)(i + 'a');
				swap(curr, terminal[i]);
				break;
			}
		}
	}

	cout << sol << '\n';
}