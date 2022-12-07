#include <cstdio>
#include <cstring>

const int MAXNODE = 100005;
const int SIGMA_SIZE = 26;

struct Trie {
    int ch[MAXNODE][SIGMA_SIZE];
    int win[MAXNODE], lose[MAXNODE];
    int sz;

    void init() {
	sz = 1;
	memset(ch[0], 0, sizeof(ch[0]));
    }

    int idx(char c) {return c - 'a';}

    void insert(char *str) {
	int n = strlen(str);
	int u = 0;
	for (int i = 0; i < n; i++) {
	    int c = idx(str[i]);
	    if (!ch[u][c]) {
		memset(ch[sz], 0, sizeof(ch[sz]));
		ch[u][c] = sz++;
	    }
	    u = ch[u][c];
	}
    }

    int dfs1(int u) {
	win[u] = 0;
	for (int i = 0; i < SIGMA_SIZE; i++) {
	    int v = ch[u][i];
	    if (!v) continue;
	    int tmp = dfs1(v);
	    if (!tmp) win[u] = 1;
	}
	return win[u];
    }

    int dfs2(int u) {
	lose[u] = 0;
	int bo = 1;
	for (int i = 0; i < SIGMA_SIZE; i++) {
	    int v = ch[u][i];
	    if (!v) continue;
	    bo = 0;
	    int tmp = dfs2(v);
	    if (!tmp) lose[u] = 1;
	}
	if (bo) return lose[u] = 1;
	return lose[u];
    }

    void getsg() {
	dfs1(0);
	dfs2(0);
    }
};

const int N = 100005;
int n, k;
char str[N];
Trie gao;

bool judge() {
    gao.init();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
	scanf("%s", str);
	gao.insert(str);
    }
    gao.getsg();
    if (gao.win[0] && gao.lose[0])
	return true;
    if (gao.win[0]) {
	if (k&1) return true;
	return false;
    }
    return false;
}

int main() {
    if (judge()) printf("First\n");
    else printf("Second\n");
    return 0;
}