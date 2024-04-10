#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
using namespace std;

int n;
long long k;
long long a[200005];

const long long INF = 2'000'000'000'000'000'000ll;

long long gcd(long long a, long long b) {
	long long t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

vector<long long> pw(const vector<long long>& a, long long k) {
	vector<long long> bseq(a.size());
	vector<long long> b(a.size());

	bseq[0] = 1;
	for (int i=1; i<a.size(); i++) {
		double proba = bseq[i-1] * 1.0 * (k+i-1) / i;

		if (proba > INF) {
			bseq[i] = INF;
		} else {
			long long a = bseq[i-1];
			long long b = k+i-1;
			long long c = i;

			long long g = gcd(a, c);
			a /= g;
			c /= g;

			g = gcd(b, c);
			b /= g;
			c /= g;

			// at this point c = 1
			bseq[i] = a*b / c;
		}
	}

	/*
	cerr << "bseq\n";
	for (auto x : bseq) {
		cerr << x << ' ';
	}
	cerr << "\n";
	*/

	for (int i=0; i<a.size(); i++) {
		double re = 0;
		long long wh = 0;

		for (int j=0; j<=i; j++) {
			wh += bseq[j] * a[i-j];
			re += bseq[j] * 1.0 * a[i-j];
		}

		if (re > INF) {
			wh = INF;
		}

		b[i] = wh;
	}

	return b;
}

void pfs(vector<long long>& a) {
	for (int i=1; i<a.size(); i++) {
		a[i] += a[i-1];
		if (a[i] > INF) {
			a[i] = INF;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	int j = 0;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i] > 0 && j == 0) {
			j = i;
		}
	}
	vector<long long> b(a+j, a+n+1);

	if (b.size() < 50) {
		// nadji naprednom tehnikom
		long long l = 0, r = INF, m, o = -1;

		while (l <= r) {
			m = (l + r) / 2;
			auto c = pw(b, m);

			/*
			cerr << m << '\n';
			for (auto x : c) {
				cerr << x << ' ';
			}
			cerr << '\n';
			*/

			if (*max_element(c.begin(), c.end()) >= k) {
				o = m;
				r = m-1;
			} else {
				l = m+1;
			}
		}

		cout << o;

	} else {
		// nadji direktno
		int s = 0;
		while (*max_element(b.begin(), b.end()) < k) {
			pfs(b);
			s++;
		}
		cout << s;
	}

}