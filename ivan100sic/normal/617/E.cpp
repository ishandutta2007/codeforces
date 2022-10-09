#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
int a[100005], b[100005], l[100005], r[100005], qq[100005];
ll ans[100005];

ll mv, mc[1 << 20];
int ml, mr;

void add(int i) {
	mv += mc[b[i] ^ k];
	mc[b[i]]++;
}

void rem(int i) {
	mc[b[i]]--;
	mv -= mc[b[i] ^ k];
}

bool cmp(int i, int j) {
	int li = l[i] >> 8;
	int lj = l[j] >> 8;
	if (li != lj)
		return li < lj;
	return r[i] < r[j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		b[i] = b[i-1] ^ a[i];
	}

	for (int i=0; i<m; i++) {
		cin >> l[i] >> r[i];
		l[i]--;
		qq[i] = i;
	}

	sort(qq, qq+m, cmp);

	ml = mr = 0;
	mc[b[0]]++;

	for (int i=0; i<m; i++) {
		int x = qq[i];
		while (mr < r[x]) add(++mr);
		while (ml > l[x]) add(--ml);
		while (mr > r[x]) rem(mr--);
		while (ml < l[x]) rem(ml++);

		ans[x] = mv;
	}

	for (int i=0; i<m; i++)
		cout << ans[i] << '\n';
}