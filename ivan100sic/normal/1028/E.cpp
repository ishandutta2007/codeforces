#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[200005], b[200005];

/*
sigurno ima resenja:
	kad postoji podniz a0*b, gde je a<b i b je max niza
	kad su sve nule
	kad su svi veci od nule jednaki ali su nesusedni

ostaje da se resi:
	kad su svi jednaki i veci od nule (assuming NE)
	kad su svi nenula jednaki i neki od njih su susedni (assuming NE)
*/

bool svi_jednaki_i_veci_0() {
	return count(b, b+n, b[0]) == n && b[0] > 0;
}

bool svi_jednaki_tesko() {
	int x = *max_element(b, b+n);
	int c0 = count(b, b+n, 0);
	int cx = count(b, b+n, x);
	return c0 + cx >= n;
}

void resi_svi_jednaki_tesko() {
	// zarotiraj nulu
	int k = find(b, b+n, 0) - b;
	k++;
	rotate(b, b+k, b+n);
	int x = *max_element(b, b+n);
	if (x == 0)
		x = 1;

	a[n-1] = x;
	for (int i=n-2; i>=0; i--) {
		if (b[i] == x)
			a[i] = a[i+1] + x;
		else
			a[i] = x;
	}

	rotate(a, a+n-k, a+n);
	rotate(a, a+n-1, a+n); // ili n-1

	cout << "YES\n";
	for (int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << '\n';
	exit(0);
}

void brutina() {
	const int n = 8;
	int b[n+1] = {0, 0, 1, 1, 1, 0, 0, 1, 0};
	const int hi = 6;

#define lup(i) for (a[i]=1; a[i]<hi; a[i]++)

	int a[n+1];
	lup(0)
	lup(1)
	lup(2)
	lup(3)
	lup(4)
	lup(5)
	lup(6)
	lup(7)
	{
		a[n] = a[0];
		b[n] = b[0];

		int k = 0;

		for (int i=0; i<n; i++)
			if (a[i] % a[i+1] == b[i])
				k++;

		if (k == n) {
			for (int i=0; i<n; i++)
				cerr << a[i] << ' ';
			return;
		}
	}
}

void resi_ab() {
	int k = 0;
	int xx = *max_element(b, b+n);
	int prethodni = -1;

	for (int i=0; i<n; i++) {
		if (b[i] == xx && prethodni != xx && prethodni != -1)
			k = i;

		if (b[i] > 0)
			prethodni = b[i];
	}

	for (int i=0; i<n; i++) {
		if (b[i] == xx && prethodni != xx && prethodni != -1)
			k = i;

		if (b[i] > 0)
			prethodni = b[i];
	}

	if (k == n)
		k = 0;
	k++;

	rotate(b, b+k, b+n);

	a[n-1] = b[n-1];
	for (int i=n-2; i>=0; i--)
		a[i] = a[i+1] + b[i];

	rotate(a, a+n-k, a+n);

	cout << "YES\n";
	for (int i=0; i<n; i++)
		cout << a[i] << ' ';
	exit(0);
}

void nema() {
	cout << "NO\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// brutina();

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> b[i];
	b[n] = b[0];

	if (svi_jednaki_i_veci_0())
		nema();

	if (svi_jednaki_tesko())
		resi_svi_jednaki_tesko();

	resi_ab();
}