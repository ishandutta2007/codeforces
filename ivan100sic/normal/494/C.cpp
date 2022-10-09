#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r;
	ld p;

	bool operator< (const seg& b) const {
		return make_pair(l, -r) < make_pair(b.l, -b.r);
	}
};

struct rasp {
	int baza;
	vector<ld> prob;

	rasp operator+ (const rasp& b) const {
		rasp t;
		t.baza = max(baza, b.baza);
		int k = max(prob.size(), b.prob.size());
		vector<ld> u(k), v(k);
		for (int i=0; i<(int)prob.size(); i++)
			u[max(0, i + baza - t.baza)] += prob[i];
		for (int i=0; i<(int)b.prob.size(); i++)
			v[max(0, i + b.baza - t.baza)] += b.prob[i];

		for (int i=1; i<k; i++) {
			u[i] += u[i-1];
			v[i] += v[i-1];
		}
		for (int i=0; i<k; i++)
			u[i] *= v[i];
		t.prob.resize(k);
		t.prob[0] = u[0];
		for (int i=1; i<k; i++)
			t.prob[i] = u[i] - u[i-1];
		return t;
	}

	void add(ld p) {
		int k = prob.size();
		vector<ld> t(k+1);
		for (int i=0; i<k; i++)
			t[i+1] += p * prob[i], t[i] += (1-p) * prob[i];
		swap(t, prob);
	}

	ld e() const {
		ld z = 0;
		for (int i=0; i<(int)prob.size(); i++)
			z += i * prob[i];
		return z + baza;
	}
};

int n, m;
int a[100005];
seg b[5005];

rasp resi(int l, int r) {
	int q = l;
	int resto = 0;
	rasp z = {0, {1}};
	for (int i=0; i<m; i++) {
		if (q <= b[i].l && b[i].r <= r && (b[i].l != l || b[i].r != r)) {
			resto = max(resto, *max_element(a+q, a+b[i].l));
			z = z + resi(b[i].l, b[i].r);
			q = b[i].r + 1;
		}
	}
	if (q <= r)
		resto = max(resto, *max_element(a+q, a+r+1));
	z = z + rasp{resto, {1}};
	for (int i=0; i<m; i++) {
		if (l == b[i].l && r == b[i].r) {
			z.add(b[i].p);
		}
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=0; i<m; i++)
		cin >> b[i].l >> b[i].r >> b[i].p;
	sort(b, b+m);
	cout << setprecision(20) << fixed << resi(1, n).e() << '\n';
}