#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 4e6 + 10;
int n, Max[N], Min[N], tag[N], pos[N];
char s[N];
void addtag(int u, int v) {
	Max[u] += v; Min[u] += v; tag[u] += v;
}
void up(int u) {
	Min[u] = min(Min[u << 1], Min[u << 1 | 1]);
	Max[u] = max(Max[u << 1], Max[u << 1 | 1]);
}
void down(int u) {
	if(tag[u] == 0) return ;
	addtag(u << 1, tag[u]);
	addtag(u << 1 | 1, tag[u]);
	tag[u] = 0;
}
void modify(int u, int l, int r, int ql, int qr, int v) {
	if(l == ql && r == qr) { addtag(u, v); return ; }
	int mid = (l + r) >> 1; down(u);
	if(qr <= mid) modify(u << 1, l, mid, ql, qr, v);
	else if(ql > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, v);
	else {
		modify(u << 1, l, mid, ql, mid, v);
		modify(u << 1 | 1, mid + 1, r, mid + 1, qr, v);
	}
	up(u);
}
int main() {
	scanf("%d%s", &n, s + 1);
	int p = 1, sum = 0;
	for(int i = 1; i <= n; i ++) {
		if(s[i] == 'L') p = p == 1 ? 1 : p - 1;
		else if(s[i] == 'R') p ++;
		else if(s[i] == '(' || s[i] == ')') {
			int v = (s[i] == '(' ? 1 : -1) - pos[p];
			if(v) modify(1, 1, n, p, n, v), pos[p] += v, sum += v;
		} else {
			if(pos[p]) modify(1, 1, n, p, n, - pos[p]), sum -= pos[p], pos[p] = 0;
		}
		printf("%d%c", sum != 0 || Min[1] < 0 ? -1 : Max[1], " \n"[i == n]);
	}
	return 0;
}