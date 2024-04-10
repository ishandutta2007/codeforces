#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> st[26],t[26];
int main() {
	int n, i, j,k;
	string s;
	cin >> s;
	n = s.size();
	for (i = 0; i < n; i++)s[i]-='a',s.push_back(s[i]);
	for (i = 0; i < n; i++)st[s[i]].push_back(i);
	int ans = 0;
	for (i = 0; i < 26; i++) {
		int ch = 0;
		for (j = 1; j < n; j++) {
			int poss = 0;
			for (k = 0; k < 26; k++)t[k].clear();
			for (k = 0; k < st[i].size(); k++) {
				t[s[j + st[i][k]]].push_back(k);
			}
			for (k = 0; k < 26; k++)if (t[k].size() == 1)poss++;
			int jjj = 000;
			ch = max(ch, poss);
		}
		ans += ch;
	}
	printf("%lf", 1.0*ans / n);
}