#include<bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int tt, n, ofs;
int a[MAXN], b[MAXN], tmpa[MAXN], tmpb[MAXN], pos[MAXN];
pair <int, int> pii[MAXN];
int t[MAXN * 4];

bool isti () {
	sort(tmpa, tmpa + n);
	sort(tmpb, tmpb + n);
	for (int i=0; i<n; i++) {
		if (tmpa[i] != tmpb[i]) return 0;
	}
	return 1;
}

void perm () {
	for (int i=0; i<n; i++) {
		pii[i] = make_pair(a[i], i);
	}
	sort(pii, pii + n);
	for (int i=0; i<n; i++) {
		a[pii[i].second] = i + 1;
	}
	for (int i=0; i<n; i++) {
		pii[i] = make_pair(b[i], i);
	}
	sort(pii, pii + n);
	for (int i=0; i<n; i++) {
		b[pii[i].second] = i + 1;
	}
}

void build () {
	ofs = 1;
	while (ofs < n) ofs *= 2;
	for (int i=0; i<ofs; i++) {
		t[i + ofs] = 0;
	}
	for (int i=0; i<n; i++) {
		t[i + ofs] = a[i];
	}
	for (int i = ofs-1; i > 0; i--) {
		t[i] = max(t[2*i], t[2*i+1]);
	}
}

int upit (int x, int from, int to, int low, int high) {
	if (from <= low && high <= to) return t[x];
	if (to < low || high < from) return 0;
	return max(upit(2*x, from, to, low, (low + high)/2), upit(2*x+1, from, to, (low + high)/2+1, high));
}

void update (int pos, int val) {
	pos += ofs;
	t[pos] = val;
	pos /= 2;
	while (pos > 0) {
		t[pos] = max(t[pos*2], t[pos*2+1]);
		pos /= 2;
	}
}

bool rjesi () {
	for (int i=n-1; i>=0; i--) {
		int br = b[i];
		int val = upit(1, pos[br] + 1, n-1, 0, ofs-1);
		if (br < val) return 0;
		update(pos[br], 0);
	}
	return 1;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> tt;
	for (int tc = 0; tc < tt; tc++) {
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			tmpa[i] = a[i];
		}
		for (int i=0; i<n; i++) {
			cin >> b[i];
			tmpb[i] = b[i];
		}
		if (!isti()) {
			cout << "NO\n";
			continue;
		}
		perm();
		for (int i=0; i<n; i++) {
			pos[a[i]] = i;
		}
		build();
		if (rjesi()) cout << "YES\n"; else cout << "NO\n";
	}
	return 0;
}