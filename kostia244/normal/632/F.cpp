#include<bits/stdc++.h>
using namespace std;
int n, mat[2600][2600];
bitset<2600> rl[2600], cl[2600], t;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<pair<int, pair<int, int>>> s;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++) {
		cin >> mat[i][j];
		s.push_back({mat[i][j], {i, j}});
	}
	for(int i = 0; i < n; i++) if(mat[i][i]) return cout << "NOT MAGIC", 0;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++) if(mat[i][j]!=mat[j][i]) return cout << "NOT MAGIC", 0;
	sort(s.begin(), s.end());
	int i = 0, j;
	while(i < s.size()) {
		j=i;
		while(j < s.size() && s[j].first == s[i].first) j++;
		for(int k = i; k < j; k++){
			t = cl[s[k].second.first]&rl[s[k].second.second];
			if(t.count()) return cout << "NOT MAGIC", 0;
		}
		for(int k = i; k < j; k++){
			cl[s[k].second.first].set(s[k].second.second);
			rl[s[k].second.second].set(s[k].second.first);
		}
		i=j;
	}
	cout << "MAGIC";
}