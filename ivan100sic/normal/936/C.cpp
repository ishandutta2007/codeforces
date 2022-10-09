#include <bits/stdc++.h>
using namespace std;

int n;
string s, p;
int a[2005];
int temp[2005];
int zemp[2005];

vector<int> b;

void do_op(int x) {
	copy(a, a+n-x, temp);
	copy(a+n-x, a+n, zemp);
	reverse(zemp, zemp+x);
	copy(zemp, zemp+x, a);
	copy(temp, temp+n-x, a+x);

	b.push_back(x);
}

void do_moves(int l, int i) {
	do_op(n-i);
	do_op(i-l);
	do_op(l+1);
}

void moze() {
	string ss = s, pp = p;
	sort(ss.begin(), ss.end());
	sort(pp.begin(), pp.end());

	if (ss != pp) {
		cout << -1;
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s >> p;

	moze();

	for (int i=0; i<n; i++) {
		int j = find(p.begin(), p.end(), s[i]) - p.begin();
		a[i] = j;
		p[j] = '.';
	}

	// proveriti parnost
	int lo = (n-1)/2;
	int hi = lo+1;

	bool raste = true;

	for (int i=0; i<n; i++) {
		int j;
		if (raste) {
			j = find(a, a+n, lo) - a;
			lo--;
		} else {
			j = find(a, a+n, hi) - a;
			hi++;
		}
		do_moves(i, j);
		raste = !raste;
	}

	if (!raste) {
		do_op(n);
	}

	cerr << is_sorted(a, a+n) << '\n';

	cout << b.size() << '\n';
	for (int x : b) {
		cout << x << ' ';
	}
	cout << '\n';
}