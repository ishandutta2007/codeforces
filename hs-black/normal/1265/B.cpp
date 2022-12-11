#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return x;
}

const int N = 405000;
int T, n;
int f[N], t[N];
int v[N], siz[N];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

inline void merge(int x,int y) {
	int fx = find(x), fy = find(y);
	siz[fx] += siz[fy];
	f[f[fy]] = fx;
}

int main() {
	T = read();
	while (T--) {
		n = read();
		for (int i = 1;i <= n; i++) siz[i] = 1, f[i] = i, v[i] = 0;
		for (int i = 1;i <= n; i++) t[read()] = i; v[n+1] = 0;
		for (int i = 1;i <= n; i++) {
			v[t[i]] = 1;
			if (v[t[i]+1]) merge(t[i], t[i] + 1);
			if (v[t[i]-1]) merge(t[i], t[i] - 1);
			if (siz[find(t[i])] == i) putchar('1');
			else putchar('0');
		}
		putchar('\n');
	}
	return 0;
}

/*
3
5
5 3 1 2 4
4
1 4 3 2
6
4 5 1 3 2 6

*/