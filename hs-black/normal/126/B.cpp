#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

const int N = 1005000;
int nxt[N], kmp[N];
char s[N];

void wandan() {
	cout << "Just a legend" << endl;
	exit(0);
}

int main() {
	scanf ("%s", s + 1);
	int j = 0, n = strlen(s + 1);
	for (register int i = 2;i <= n; i++) {
		while (j && s[i] != s[j+1]) j = nxt[j];
		if (s[i] == s[j+1]) j++;
		nxt[i] = j, kmp[j]++;
	}
	kmp[nxt[n]]--;
	if (!nxt[n]) wandan();
	j = nxt[n];
	while (j) {
		if (kmp[j]) {
			for (register int i = 1;i <= j; i++) putchar(s[i]);
			cout << endl;
			return 0;
		}
		j = nxt[j];
	}
	wandan();
	return 0;
}