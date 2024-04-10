#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005], b[100005], n;
int c[100005], d[100005];

// (a)dd, (d)elete
// (r)ising, (f)alling
basic_string<int> ar[100005], af[100005], dr[100005], df[100005];

struct lazy_ms {
	int offset;
	multiset<int> ms;

	void add(int x) {
		ms.insert(x - offset);
	}

	void rem(int x) {
		ms.erase(ms.find(x - offset));
	}

	void delta(int x) {
		offset += x;
	}

	int min() {
		if (ms.empty())
			return 123123123;
		return offset + *ms.begin();
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	fill(c, c+n, 123123123);
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		x--;
		a[x] = i;
	}
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		x--;
		b[x] = i;
	}

	for (int i=0; i<n; i++) {
		int b = ::b[i];
		int a = ::a[i];
		if (b <= a) {
			// opada od 0 do b-a
			af[0] += a-b;
			df[a-b] += 0;
			// raste 
			ar[a-b] += 0;
			dr[n-b] += n-a;
			// opada do n
			af[n-b] += a;
			df[n] += a-b;
		} else {
			// raste od 0 do n-b
			ar[0] += b-a;
			dr[n-b] += n-a;
			// opada od n-b do a-b+n
			af[n-b] += a;
			df[a-b+n] += 0;
			// raste do kraja
			ar[a-b+n] += 0;
			dr[n] += b-a;
		}
	}

	lazy_ms raste, pada;
	for (int i=0; i<n; i++) {
		for (int x : ar[i])
			raste.add(x);
		for (int x : af[i])
			pada.add(x);
		for (int x : dr[i])
			raste.rem(x);
		for (int x : df[i])
			pada.rem(x);

		d[i] = min(raste.min(), pada.min()); // sav sam naopak
		raste.delta(1);
		pada.delta(-1);
	}
	reverse(d+1, d+n);
	for (int i=0; i<n; i++)
		cout << d[i] << '\n';
}