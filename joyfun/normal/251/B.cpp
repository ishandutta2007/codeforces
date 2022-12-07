#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 105;
int n, k, p[N], q[N], s[N], tmp[N];

bool eq() {
	for (int i = 1; i <= n; i++) if (p[i] != s[i]) return false;
	return true;
}

void g1() {
	for (int i = 1; i <= n; i++) tmp[q[i]] = p[i];
	for (int i = 1; i <= n; i++) p[i] = tmp[i];
}

void g2() {
	for (int i = 1; i <= n; i++) tmp[i] = p[q[i]];
	for (int i = 1; i <= n; i++) p[i] = tmp[i];
}

bool judge(int s1, int s2) {
	if (s1 == 0 && s2 == 0) return false;
	if (s1 == k || s2 == k) return true;
	if ((k - s1) % 2 == 0 && s1 > 1) return true;
	if ((k - s2) % 2 == 0 && s2 > 1) return true;
	if ((k - s1) % 2 == 0 && s1 == 1 && s2 != 1) return true;
	if ((k - s2) % 2 == 0 && s2 == 1 && s1 != 1) return true;
	return false;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &q[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
	for (int i = 1; i <= n; i++) p[i] = i;
	if (eq()) {
		printf("NO\n");
		return 0;
	}
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= k; i++) {
		g1();
		if (eq()) {
			s1 = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= k; i++) {
		g2();
		if (eq()) {
			s2 = i;
			break;
		}
	}
	printf("%s\n", judge(s1, s2) ? "YES" : "NO");
	return 0;
}