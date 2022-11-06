#include <cstdio>

/** Interface */

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt(T x);
inline void writeChar( int x );
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 1 << 14;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int c = readChar();
	T x = 0;
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt(T x) {
	static char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	writeChar('\n');
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;






#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7;
const int maxn = 1e6 + 5;
const int LOG = 21;

int n, q;
int head[maxn], nxt[2 * maxn], edge[2 * maxn], last_edge = 1;
pair<int, int> mi[maxn];
int ind_first[maxn];
int minval[maxn][LOG];
int ancestor[maxn][LOG];
int parent[maxn]; //in centroid tree

int find_centroid(int v, int p, int &centroid, int n) {
    int sz = 1;
    for (int ind = head[v]; ind; ind = nxt[ind]) {
        int to = edge[ind];
        if (to != p && !parent[to]) {
            sz += find_centroid(to, v, centroid, n);
            if (centroid) return 0;
        }
    }
    if (sz * 2 >= n) {
        centroid = v;
    }
    return sz;
}

void dfs(int root, int p, int level) {
    static int vertex[maxn], par[maxn], pstack = 0, v;
    vertex[pstack] = root;
    par[pstack++] = p;
    while (pstack) {
        v = vertex[--pstack];
        p = par[pstack];
        minval[v][level] = min(v, minval[p][level]);
        ancestor[v][level] = root;
        for (int ind = head[v]; ind; ind = nxt[ind]) {
            int to = edge[ind];
            if (to != p && !parent[to]) {
                vertex[pstack] = to;
                par[pstack++] = v;
            }
        }
    }
}

void build(int v, int p, int level, int sz) {
    assert(level < LOG);
    int centroid = 0;
    find_centroid(v, -1, centroid, sz);
    v = centroid ? centroid: v;
    parent[v] = p;
    minval[v][level] = v;
    ancestor[v][level] = -1;
    for (int ind = head[v]; ind; ind = nxt[ind]) {
        int to = edge[ind];
        if (!parent[to]) {
            dfs(to, v, level);
            build(to, v, level + 1, (sz + 1) / 2);
        }
    }
}

inline void combine(int centroid, int val, int anc) {
    if (ind_first[centroid] == anc) {
        mi[centroid].first = min(mi[centroid].first, val);
    } else if (val < mi[centroid].second) {
        mi[centroid].second = val;
        if (mi[centroid].second < mi[centroid].first) {
            swap(mi[centroid].first, mi[centroid].second);
            ind_first[centroid] = anc;
        }
    }
}

inline int getmin(int centroid, int val, int anc) {
    int tmp = (ind_first[centroid] == -1 || ind_first[centroid] != anc) ? mi[centroid].first: mi[centroid].second;
    return tmp == INF ? INF: min(tmp, val);
}

void paint(int v) {
    int centroid = -1;
    for (int level = LOG - 1; level >= 0; --level) {
        if (centroid == -1 && minval[v][level] != INF) {
            centroid = v;
        }
        if (centroid != -1) {
            combine(centroid, minval[v][level], ancestor[v][level]);
            centroid = parent[centroid];
        }
    }
}

int get(int v) {
    int centroid = -1;
    int ans = INF;
    for (int level = LOG - 1; level >= 0; --level) {
        if (centroid == -1 && minval[v][level] != INF) {
            centroid = v;
        }
        if (centroid != -1) {
            ans = min(ans, getmin(centroid, minval[v][level], ancestor[v][level]));
            centroid = parent[centroid];
        }
    }
    return ans;
}

void init() {
    for (int i = 1; i <= n; ++i) {
        mi[i] = {INF, INF};
        ind_first[i] = -1;
        for (int j = 0; j < LOG; ++j) {
            minval[i][j] = INF;
        }
    }
    build(1, -1, 0, n);
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    n = readInt();
    q = readInt();
    for (int i = 1; i < n; ++i) {
        int a = readInt();
        int b = readInt();
        nxt[last_edge] = head[a];
        head[a] = last_edge;
        edge[last_edge++] = b;
        nxt[last_edge] = head[b];
        head[b] = last_edge;
        edge[last_edge++] = a;
    }

    init();
    int last = 0;
    for (int i = 0; i < q; ++i) {
        int tp = readInt();
        int v = readInt();
        v = (v + last) % n + 1;
        if (tp == 1) {
            paint(v);
        } else {
            last = get(v);
            writeInt(last);
        }
    }
}