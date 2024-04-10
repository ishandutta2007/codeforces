#include <bits/stdc++.h>
using namespace std;

vector<int> pos[256];
string s;
bool used[400005];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> s;
	for (int i=0; i<n; i++)
		pos[(int)s[i]].push_back(i);

	for (int i='a'; i<='z'; i++)
		reverse(pos[i].begin(), pos[i].end());

	for (int i=0; i<k; i++) {
		for (int j='a'; j<='z'; j++) {
			if (pos[j].size()) {
				used[pos[j].back()] = 1;
				pos[j].pop_back();
				break;
			}
		}
	}

	for (int i=0; i<n; i++)
		if (!used[i])
			cout << s[i];
}