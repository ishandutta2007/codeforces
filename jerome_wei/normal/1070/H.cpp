#include <bits/stdc++.h>

#define IL __inline__ __attribute__((always_inline))

#define For(i, a, b) for (int i = a, i##end = b; i <= i##end; ++ i)
#define FOR(i, a, b) for (int i = a, i##end = b; i < i##end; ++ i)
#define Rep(i, a, b) for (int i = a, i##end = b; i >= i##end; -- i)
#define REP(i, a, b) for (int i = a - 1, i##end = b; i >= i##end; -- i)

typedef long long LL;

template <class T>
IL bool chkmax(T &a, const T b) {
  return a < b ? ((a = b), 1) : 0;
}

template <class T>
IL bool chkmin(T &a, const T b) {
  return a > b ? ((a = b), 1) : 0;
}

template <class T>
IL T mymax(const T a, const T b) {
  return a > b ? a : b;
}

template <class T>
IL T mymin(const T a, const T b) {
  return a < b ? a : b;
}

template <class T>
IL T myabs(const T &a) {
  return a > 0 ? a : -a;
}

const int INF = 0X3F3F3F3F;
const double EPS = 1E-10, PI = acos(-1.0);

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define OK DEBUG("Passing [%s] in LINE %d...\n", __FUNCTION__, __LINE__)
#define F first
#define S second
/*************************header*************************/

const int MAXN = 50000 + 5, MAXQ = 50000 + 5, MAXM = 500000 + 5, MAXL = 10 + 5, ALPHA = 40;

char text[MAXM][MAXL];
int len[MAXM], ans[MAXQ], get[MAXM];

struct AhoCorasickAutomaton {
	int c[ALPHA][MAXM], nxt[MAXM], fail[MAXM], ok[MAXM], vis[MAXM], cnt;
	std::vector <int> res[MAXM];
	
	AhoCorasickAutomaton() {
		memset(c, -1, sizeof c);
		memset(nxt, -1, sizeof nxt);
		memset(fail, -1, sizeof fail);
	}
	
#define id(x) (islower(x) ? x - 'a' : isdigit(x) ? 26 + x - '0' : 36)
	void count(int x, int k) {
	  if (vis[x] == k || !x)
	    return;
	  vis[x] = k;
		for (auto &i : res[x]) {
		  if (!ans[i])
		    get[i] = k;
		  ++ ans[i];
		}
		if (nxt[x] != -1)
			count(nxt[x], k);
	}

	void insert(char *str, int n, int num) {
		int cur = 0;
		For(i, 1, n) {
			if (c[id(str[i])][cur] == -1)
				c[id(str[i])][cur] = ++ cnt;
			cur = c[id(str[i])][cur];
		}
		ok[cur] = 1;
		res[cur].push_back(num);
	}
	
	int que[MAXN];
	void build() {
		int l = 1, r = 0;
		que[++ r] = 0;
		fail[0] = 0;
		while (l <= r) {
			int cur = que[l ++];
			FOR(i, 0, ALPHA) {
				if (c[i][cur] == -1) {
					c[i][cur] = cur ? c[i][fail[cur]] : 0;
					continue;
				}
				fail[c[i][cur]] = cur && c[i][fail[cur]] != -1 ? c[i][fail[cur]] : 0;
				nxt[c[i][cur]] = ok[fail[c[i][cur]]] ? fail[c[i][cur]] : nxt[fail[c[i][cur]]];
				que[++ r] = c[i][cur];
			}
		}
	}
	
	void get_ans(char *str, int n, int k) {
		int cur = 0;
		For(i, 1, n) {
			cur = c[id(str[i])][cur];
			if (ok[cur])
				count(cur, k);
			else if (nxt[cur] != -1)
				count(nxt[cur], k);
		}
	}
} M;

char str[MAXL];

int main() {
  int n;
  scanf("%d", &n);
  For(i, 1, n) {
    scanf("%s", text[i] + 1);
    len[i] = strlen(text[i] + 1);
  }
  int q;
  scanf("%d", &q);
  For(i, 1, q) {
    scanf("%s", str + 1);
    int length = strlen(str + 1);
    M.insert(str, length, i);
  }
  M.build();
  For(i, 1, n)
    M.get_ans(text[i], len[i], i);
  For(i, 1, q) {
    if (ans[i]) {
      printf("%d %s\n", ans[i], text[get[i]] + 1);
    } else
      puts("0 -");
  }
  return 0;
}