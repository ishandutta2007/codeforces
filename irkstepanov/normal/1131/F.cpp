#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int nmax = 200500;

int parent[nmax];
int size[nmax];

vector<int> a[nmax];

int get(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = get(parent[v]);
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
		size[i] = 1;
		a[i] = {i};
	}

	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		x = get(x), y = get(y);
		if (size[x] < size[y]) {
			swap(x, y);
		}
		parent[y] = x;
		size[x] += size[y];
		for (int z : a[y]) {
			a[x].pb(z);
		}
	}

	int pos = get(0);
	for (int x : a[pos]) {
		cout << x + 1 << " ";
	}
	cout << "\n";

}