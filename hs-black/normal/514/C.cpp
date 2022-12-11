#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 605000;
char s[N];
int trie[N][4];
int tot;
int en[N];
void add(char *s) {
	int len = strlen(s+1);
	int p = 0;
	for (int i = 1;i <= len; i++) {
		int ch = s[i] - 'a';
		if (!trie[p][ch]) trie[p][ch] = ++tot;
		p = trie[p][ch];
	}
	en[p] = 1;
}

bool dfs(int len,int i,int flag,int p) {
	if (len == i - 1) {
		if (en[p] && flag) return true;
		return false;
	}
	int ch = s[i] - 'a';
	for (int k = 0;k < 3; k++) {
		if (trie[p][k]) {
			if (k == ch) {
				if (dfs(len, i + 1, flag, trie[p][k])) 
				return true;
			}
			else {
				if (flag) continue;
				if (dfs(len, i + 1, 1, trie[p][k])) 
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n; i++) {
		scanf ("%s", s + 1);
		add(s);
	}
	for (int i = 1;i <= m; i++) {
		scanf ("%s", s + 1);
		int len = strlen(s + 1);
		if (dfs(len, 1, 0, 0))
			printf ("YES\n");
		else 
			printf ("NO\n");
	}
	return 0;
}