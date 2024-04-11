#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pi pair<int, int>
#define __V vector
#define vi __V<int>
using namespace std;
int n, g[26][26], s = -1;
__V<string> str;
string ans;
int vis[30], in[30];
vi ord;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	str.resize(n);
	for (auto& i : str)
		cin >> i;
	for (int i = 1; i < n; i++) {
		int l = 0;
		while (l < min(str[i].size(), str[i - 1].size())
				&& str[i - 1][l] == str[i][l])
			l++;
		if (l < min(str[i].size(), str[i - 1].size()))
			g[str[i - 1][l] - 'a'][str[i][l] - 'a'] = 1;
		if (l < min(str[i].size(), str[i - 1].size()) && s == -1)
			s = str[i - 1][l] - 'a';
		if (l == min(str[i].size(), str[i - 1].size()) && str[i][--l] == str[i-1][l] && str[i-1].size() > str[i].size()) {
			return cout << "Impossible", 0;
		}
	}
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			if (g[i][j])
				in[j]++;
	for(int i = 0; i < 26; i++)
		if(in[i] == 0)
			ord.pb(i);
	int i = 0;
	while(i < ord.size()) {
		for(int j = 0; j < 26; j++)
			if(g[ord[i]][j] == 1)
				if(--in[j] == 0)
					ord.pb(j);
		i++;
	}
	if(ord.size() != 26)
		cout << "Impossible";
	else
		for(auto& i : ord) cout << char('a' + i);
}