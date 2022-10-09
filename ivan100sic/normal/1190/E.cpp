#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<ld> cd;

const ld pi = acos(ld(-1));
const ld tau = 2*pi;

int n, m;
cd a[100005];

pair<ld, ld> tangente(cd p, ld r) {
	ld dp = arg(p);
	ld alpha = acos(r / abs(p));
	ld u = dp - alpha;
	ld v = dp + alpha;
	if (u < 0) {
		u += tau;
		v += tau;
	} else if (u >= 2*pi) {
		u -= tau;
		v -= tau;
	}
	return {u, v};
}

struct endpoint {
	ld x;
	int id, t;
	bool operator< (const endpoint& b) const {
		return x < b.x;
	}
};

struct segment {
	ld l, r;
};

segment v[300005];
endpoint b[600005];
int nx[300005], pw[300005];
vector<int> e[300005], init;
vector<int> st;

void dfs(int x) {
	st.push_back(x);

	if ((int)st.size() >= m) {
		pw[x] = st[st.size()-m];
	} else {
		pw[x] = -1;
	}

	for (int y : e[x])
		dfs(y);

	st.pop_back();
}

bool moze(ld d, int write = 0) {
	for (int i=0; i<n; i++) {
		tie(v[i].l, v[i].r) = tangente(a[i], d);
		if (isnan(v[i].l))
			return false;
		v[i+1*n].l = v[i].l + 1*tau;
		v[i+1*n].r = v[i].r + 1*tau;
		v[i+2*n].l = v[i].l + 2*tau;
		v[i+2*n].r = v[i].r + 2*tau;
	}

	for (int i=0; i<3*n; i++) {
		b[2*i+0] = {v[i].l, i, +1};
		b[2*i+1] = {v[i].r, i, -1};
	}

	sort(b, b+6*n);

	// za svaki segment nadji od svih koji imaju vece L
	// onaj koji ima najmanje R

	ld naj_r = 1e50;
	int idx = -1;

	for (int i=6*n-1; i>=0; i--) {
		if (b[i].t == +1) {
			// dodajemo njegovo R
			if (v[b[i].id].r < naj_r) {
				naj_r = v[b[i].id].r;
				idx = b[i].id; 
			}
		} else {
			// resavamo ga
			nx[b[i].id] = idx;
		}
	}

	// za svaki cvor i nadji nx^m(i)
	for (int i=0; i<3*n; i++)
		e[i].clear();
	init.clear();

	for (int i=0; i<3*n; i++) {
		if (nx[i] != -1) {
			e[nx[i]].push_back(i);
		} else {
			init.push_back(i);
		}
	}

	for (int x : init)
		dfs(x);

	for (int i=0; i<n; i++) // ne moras ove posle
		if (pw[i] != -1 && v[pw[i]].r < tau + v[i].r) {
			//..
		} else {
			return true;
		}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	m++;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = cd(x, y);
		if (x == 0 && y == 0) {
			cout << "0\n";
			return 0;
		}
	}

	ld l = 0, r = 142000, o = 0;
	int steps = 39;
	while (steps--) {
		ld m = (l+r) / 2;
		if (moze(m)) {
			o = m;
			l = m;
		} else {
			r = m;
		}
	}
	cout << setprecision(20) << fixed << o << '\n';
}