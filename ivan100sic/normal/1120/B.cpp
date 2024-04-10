#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string a, b;

int razlika(string s) {
	int z = 0;
	for (int i=0; i<n; i++) {
		int x = s[i] - '0';
		if (i % 2)
			z -= x;
		else
			z += x;
	}
	return z;
}

basic_string<pair<int, int>> movs;
int sol;
ll ovosamnekakoizracunao;

void umri() {
	cout << ovosamnekakoizracunao << '\n';
	cerr << sol << '\n';
	for (auto [x, y] : movs)
		cout << x+1 << ' ' << y << '\n';
	exit(0);
}

void add_emd(basic_string<int> r) {
	for (int i=0; i<n-1; i++) {
		r[i+1] -= r[i];
		ovosamnekakoizracunao += abs(r[i]);
	}
}

void gen_emd() {
	basic_string<int> r;
	for (int i=0; i<n; i++) {
		r += a[i] - b[i];
	}
	add_emd(r);
}

void povecaj(int x);
void smanji(int x);
void resi(int x);

void povecaj(int x) {
	if (a[x+1] == '9')
		smanji(x+1);
	a[x]++;
	a[x+1]++;
	if (sol++ < 100000) {
		movs += {x, 1};
		// cerr << a << '\n';
	}
	else
		umri();
}

void smanji(int x) {
	if (a[x+1] == '0')
		povecaj(x+1);
	a[x]--;
	a[x+1]--;
	if (sol++ < 100000) {
		movs += {x, -1};
		// cerr << a << '\n';
	}
	else
		umri();
}

void resi(int x) {
	if (x == n-1)
		return; // nema sta da se radi
	while (a[x] < b[x])
		povecaj(x);	
	while (a[x] > b[x])
		smanji(x);
	resi(x+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b;
	if (razlika(a) != razlika(b)) {
		cout << "-1\n";
		return 0;
	}

	gen_emd();

	resi(0);
	umri();
}