// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 10000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

void smooth(int x, int n, int c, set<int>& a) {
	if (x <= n) {
		if (a.count(x))
			return;
		else
			a.insert(x);
	} else {
		return;
	}

	for (int i=0; i<c; i++)
		smooth(x*prosti[i], n, c, a);
}

bool try_solve(int n, int c) {
	int m = 2*n*n;
	set<int> a;
	smooth(1, m, c, a);
	vector<int> f(c);

	if ((int)a.size() < n)
		return false;

	while ((int)a.size() > n)
		a.erase(a.begin());

	for (int x : a)
		for (int i=0; i<c; i++)
			if (x % prosti[i] == 0)
				f[i]++;

	int me = *min_element(begin(f), end(f));
	return 2*me >= n;
}

int solve(int n) {
	int c = 2;
	while (!try_solve(n, c))
		c++;
	return c;
}

void do_solve(int n, int c) {
	int m = 2*n*n;
	set<int> a;
	smooth(1, m, c, a);
	vector<int> f(c);

	while ((int)a.size() > n)
		a.erase(a.begin());

	for (int x : a)
		cout << x << ' ';
	cout << '\n';
}

void cf(int n) {
	int c;
	if (n <= 65)
		c = 2;
	else if (n <= 406)
		c = 3;
	else if (n <= 2094)
		c = 4;
	else
		c = 5;
	do_solve(n, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	cf(n);
	return 0;

	vector<future<int>> ans(5005);
	
	for (int k=10; k<=5000; k++)
		ans[k] = async(solve, k);
	
	for (int k=10; k<=5000; k++)
		cout << k << ' ' << ans[k].get() << '\n';
}

// I will still practice daily...