#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void no() {
	cout << "-1\n";
	exit(0);
}

int levi[200005], desni[200005], invdesni[200005], invlevi[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	set<int> p0, p1;
	for (int i=0; i<n; i++) {
		if (s[i] == '0')
			p0.insert(i);
		else
			p1.insert(i);
	}

	memset(levi, 255, sizeof(levi));
	memset(desni, 255, sizeof(desni));
	memset(invdesni, 255, sizeof(invdesni));
	memset(invlevi, 255, sizeof(invlevi));

	vector<basic_string<int>> sol;

	set<int> t0 = p0;

	for (int x : p1) {
		if (t0.size() == 0)
			no();
		int y = *t0.begin();
		t0.erase(y);
		if (y > x)
			no();
		levi[x] = y;
		invlevi[y] = x;
	}

	t0 = p0;

	for (int x=n-1; x>=0; x--) {
		if (s[x] == '1') {
			if (t0.size() == 0)
				no();
			int y = *--t0.end();
			t0.erase(y);
			if (y < x)
				no();
			desni[x] = y;
			invdesni[y] = x;
		}
	}

	for (int i=0; i<n; i++) {
		if (s[i] == '0' && invdesni[i] == -1) {
			int x = i;
			basic_string<int> t = {x};
			while (invlevi[x] != -1) {
				x = invlevi[x];
				t += x;
				x = desni[x];
				t += x;
			}
			sol.push_back(t);
		}
	}

	cout << sol.size() << '\n';
	for (auto t : sol) {
		cout << t.size();
		for (int x : t)
			cout << ' ' << x+1;
		cout << '\n';
	}
}