#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 5005;
int n, m, hn, sn, len;
char s[N];
map<string, int> h;
vi g[N];

int cal(string s) {
	if (!h.count(s)) h[s] = ++hn;
	return h[s];
}

string get() {
	string ans = "";
	while (1) {
		ans += s[sn++];
		if (sn == len || s[sn] == ' ') break;
	}
	if (sn != len) sn++;
	return ans;
}

struct Node {
	string a, b, op;
	int u, v;
	Node() {}
	Node(string a, string b, string op) : a(a), b(b), op(op) {}
} node[N];

int dd[N];

void un(int u, string a) {
	if (a[0] >= 'a' && a[0] <= 'z') {
		int v = cal(a);
		g[v].push_back(u);
		dd[u]++;
	}
}

bool ck(char c) {
	return c >= 'a' && c <= 'z';
}

void gao(char *s) {
	len = strlen(s);
	sn = 0;
	string name = get(); get();
	string a = get();
	int u = cal(name);
	if (sn == len) {
		string op = "", b = "";
		un(u, a);
		node[u] = Node(a, b, op);
		//cout << u << " " << name << " " << a << endl;
	} else {
		string op = get();
		string b = get();
		un(u, a); un(u, b);
		node[u] = Node(a, b, op);
		//cout << name << " " << a << " " << op << " " << b << endl;
	}
}

int du[N], Q[N], qn = 0;
int val[N];

void ini() {
	for (int i = 1; i <= n; i++) du[i] = dd[i];
	for (int i = 1; i <= n; i++) if (!du[i]) Q[qn++] = i;
	for (int i = 0; i < qn; i++) {
		int u = Q[i];
		if (ck(node[u].a[0])) node[u].u = cal(node[u].a);
		if (ck(node[u].b[0])) node[u].v = cal(node[u].b);
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			du[v]--;
			if (!du[v]) Q[qn++] = v;
		}
	}
}

int gv(int bi, int x, string a, int u) {
	if (a == "?") return x;
	else if (ck(a[0])) return val[u];
	return a[m - bi - 1] - '0';
}

int cao(int bi, int x) {
	for (int i = 0; i < qn; i++) {
		int u = Q[i];
		if (node[u].op == "") val[u] = gv(bi, x, node[u].a, node[u].u);
		else {
			int aa = gv(bi, x, node[u].a, node[u].u);
			int bb = gv(bi, x, node[u].b, node[u].v);
			if (node[u].op[0] == 'X') val[u] = aa^bb;
			if (node[u].op[0] == 'A') val[u] = aa&bb;
			if (node[u].op[0] == 'O') val[u] = aa|bb;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += val[i];
	return ans;
}

int w[2];

int main() {
	scanf("%d%d%*c", &n, &m);
	for (int i = 1; i <= n; i++) {
		gets(s);
		gao(s);
	}
	ini();
	string ans1 = "", ans2 = "";
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < 2; j++) w[j] = cao(i, j);
		//	printf("%d %d\n", w[0], w[1]);
		ans1 += (w[0] <= w[1] ? '0' : '1');
		ans2 += (w[0] >= w[1] ? '0' : '1');
	}
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}