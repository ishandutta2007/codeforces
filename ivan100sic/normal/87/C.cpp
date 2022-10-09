#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct mexer {
	vector<int> a;

	void add(int x) {
		a.push_back(x);
	}

	int calc() {
		vector<int> b(a.size() + 1);
		for (int x : a) {
			if (x >= (int)b.size())
				continue;
			b[x] = 1;
		}
		for (int i=0; i<(int)b.size(); i++)
			if (b[i] == 0)
				return i;
		return -1;
	}
};

int d[100005];
int z[100005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int mv = 123123123;
	for (int i=1; i<=n; i++) {
		mexer mx;
		for (int k=2; k*(k+1)/2 <= i; k++) {
			int b = (2*i + k - k*k) / (2*k);
			if ((2*i + k - k*k) % (2*k) || b <= 0)
				continue;
			int w = z[b-1] ^ z[b+k-1];
			mx.add(w);
			if (i == n && w == 0) {
				mv = min(mv, k);
			}
		}
		d[i] = mx.calc();
		z[i] = z[i-1] ^ d[i];
	}

	if (d[n]) {
		cout << mv << '\n';
	} else {
		cout << "-1\n";
	}
}