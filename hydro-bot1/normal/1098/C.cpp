// Hydro submission #614447753c975fa963d7dc19@1631864693812
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500010;
long long n, s;

long long read() {
	char ch;
	long long ans = 0, f = 1;
	ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans * f;
}

long long solve(long long x) {
	long long r = n, k = 1, ans = 0, sum = 1;
	while (r >= k) {
		ans += sum * k;
	 	r -= k;
		k *= x; sum++;
	}
	ans += r * sum;
	return ans;
}
long long fa[N], son[N];
int fst[N], lst[N], nxt[N];

void qpush(int i, int x) {
	if (fst[i] == -1) 
		fst[i] = lst[i] = x;
	else {
		nxt[lst[i]] = x;
		lst[i] = x;
	}
	nxt[x] = -1;
}

void qpop(int i) {
	if (fst[i] == -1) return;
	if (nxt[fst[i]] == -1)  
		fst[i] = lst[i] = -1;
	else 
		fst[i] = nxt[fst[i]];
}

int main() {
	n = read(); s = read();
	long long l = 1, r = n - 1, d = -1, p = n * (n + 1) / 2;
	if (s < 2 * n - 1 || s > p) {
		printf("No\n");
		return 0;
	}
	while (l <= r) {
		long long mid = (l + r) >> 1;
		long long tmp = solve(mid);
		if (tmp <= s) r = mid - 1, d = mid;
		else l = mid + 1;
	}
	//printf("%d\n", d);
	for (int i = 1; i <= n; i++) fst[i] = lst[i] = -1;
	qpush(1, 1);
	for (int i = 2; i <= n; i++) {
		fa[i] = i - 1; 
		son[i - 1] = 1;
		qpush(i, i);
	}
	int t = 1;
	for (int i = n; i; i--) {
		if (p == s) break;
		while (fst[t] > 0 && son[fst[t]] == d) qpop(t);
		while (fst[t] < 0 || p - i + t + 1 < s) {
			t++;
			while (fst[t] > 0 && son[fst[t]] == d) qpop(t);
		}
		son[fst[t]]++;
		son[fa[i]]--;
		p = p - i + t + 1;
		fa[i] = fst[t];
		//printf("%d %d\n", i, fa[i]);
		qpop(i);
		qpush(t + 1, i);
	}
	//printf("%lld %lld\n", d, p);
	printf("Yes\n");
	for (int i = 2; i <= n; i++) printf("%lld ", fa[i]);
	printf("\n");
	return 0;
}