/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)


*/

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 1005, M = 100500;
int G[N][N], ed[N<<1][N], ans[M];
void dfs(int nw, int c1, int c2) {
	if (!ed[nw][c1]) { ed[nw][c2] = 0; return; }
	int to = ed[nw][c1];
	dfs(to, c2, c1);
	ed[nw][c2] = to, ed[to][c2] = nw;
}

int Ans, a, b, m;
int main() {
	read(a), read(b), read(m);
	for (int i = 1, x, y;i <= m; ++i) {
		read(x), read(y), G[x][y] = i, y += a;
		int c1 = 1, c2 = 1;
		while (ed[x][c1]) ++c1; Mx(Ans, c1);
		while (ed[y][c2]) ++c2; Mx(Ans, c2);
		if (c1 != c2) dfs(y, c1, c2);
		ed[x][c1] = y, ed[y][c1] = x;
	}
	write(Ans);
	for (int i = 1;i <= a; ++i)
		for (int j = 1;j <= Ans; ++j)
			if (ed[i][j]) ans[G[i][ed[i][j] - a]] = j;
	for (int i = 1;i <= m; ++i) write(ans[i], ' ');
	return 0;
}

/*

100 1 72
1 1
2 1
3 1
4 1
5 1
6 1
7 1
8 1
9 1
10 1
11 1
12 1
13 1
14 1
15 1
16 1
17 1
18 1
19 1
20 1
21 1
22 1
23 1
24 1
25 1
26 1
27 1
28 1
29 1
30 1
31 1
32 1
33 1
34 1
35 1
36 1
37 1
38 1
39 1
40 1
41 1
42 1
43 1
44 1
45 1
46 1
47 1
48 1
49 1
50 1
51 1
52 1
53 1
54 1
55 1
56 1
57 1
58 1
59 1
60 1
61 1
62 1
63 1
64 1
65 1
66 1
67 1
68 1
69 1
70 1
71 1
72 1

*/