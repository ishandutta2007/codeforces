#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 300050;
int trie[N*32][2];
int a[N];
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}

int en[N*32*2], tot;

void add(int x) {
	int p = 0, ch;
	for (int i = 31;i >= 0; i--) {
		ch = (x >> i) & 1;
		if (!trie[p][ch]) trie[p][ch] = ++tot;
		p = trie[p][ch];
		en[p]++;
	}
}

int ask(int x) {
	int p = 0, ch;
	int ans = 0;
	for (int i = 31;i >= 0; i--) {
		ch = (x >> i) & 1;
		if (trie[p][ch] && en[trie[p][ch]])
			p = trie[p][ch];
		else {
			p = trie[p][!ch];
			ans += 1 << i;
		}
		en[p]--;
	}
	return ans;
}

int main() {
	int n = read();
	for (int i = 1;i <= n; i++) a[i] = read();
	for (int j = 1;j <= n; j++) add(read());
	for (int i = 1;i <= n; i++)
		printf ("%d ", ask(a[i]));
	return 0;
}