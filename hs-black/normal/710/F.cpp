#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 1000500;
int c[N][26], ch[N][26], f[N];
ll en[N], sum[N], cnt, n, op;
struct Auto_AC_Dfn {
	int bit[60], rt[60];
	
	int merge(int x, int y) {
		if (!x || !y) return x | y;
		en[x] += en[y];
		for (int i = 0;i < 26; i++) 
			c[x][i] = merge(c[x][i], c[y][i]);
		return x;
	}
	
	void build(int rt) {
		queue<int> q;
		for (int i = 0;i < 26; i++) {
			ch[rt][i] = c[rt][i];
			if (ch[rt][i]) q.push(ch[rt][i]), f[ch[rt][i]] = rt;
			else ch[rt][i] = rt;
		}
		while (q.size()) {
			int x = q.front(); q.pop();
			sum[x] = en[x] + sum[f[x]];
			for (int i = 0;i < 26; i++) {
				ch[x][i] = c[x][i];
				if (ch[x][i]) f[ch[x][i]] = ch[f[x]][i], q.push(ch[x][i]);
				else ch[x][i] = ch[f[x]][i];
			}
		}
	}
	
	void add(char *s) {
		int p = rt[0], len = strlen(s + 1);
		for (int i = 1;i <= len; i++) {
			int di = s[i] - 'a';
			if (!c[p][di]) c[p][di] = ++cnt;
			p = c[p][di];
		} bit[0]++, en[p]++;
		if (bit[0] == 1) build(rt[0]);
		for (int i = 0;i < 20; i++) {
			if (bit[i] == 2) {
				rt[i+1] = merge(rt[i+1], rt[i]);
				bit[i+1]++, bit[i] = 0, build(rt[i+1]);
				memset(c[rt[i]], 0, sizeof(c[rt[i]]));
				memset(ch[rt[i]], 0, sizeof(ch[rt[i]]));
			}
			else break;
		}
	}
	
	ll query(char *s, int k) {
		int len = strlen(s + 1), p = rt[k];
		ll ans = 0;
		for (int i = 1;i <= len; i++)
			p = ch[p][s[i]-'a'], ans += sum[p];
		return ans;
	}
	
	ll query(char *s) {
		ll ans = 0;
		for (int i = 0;i <= 20; i++) 
			if (bit[i]) ans += query(s, i);
		return ans;
	}
	
}A, B;

char s[N];
int main() {
	read(n); for (int i = 0;i <= 20; i++) A.rt[i] = ++cnt, B.rt[i] = ++cnt;
	while (n--) {
		read(op); scanf ("%s", s + 1);
		if (op == 1) A.add(s);
		else if (op == 2) B.add(s);
		else printf ("%lld\n", A.query(s) - B.query(s));
		fflush(stdout);
	}
	return 0;
}
/*
10
1 a
1 aa
3 aaaa


*/