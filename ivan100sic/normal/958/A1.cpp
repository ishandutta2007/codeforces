#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
char a[15][15];
char b[15][15];

bool eq() {
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			if (a[i][j] != b[i][j])
				return false;
	return true;
}

void rot() {
	char c[15][15];
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			c[i][j] = a[n-j][i];
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			a[i][j] = c[i][j];
}

void flip() {
	char c[15][15];
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			c[i][j] = a[n-i][j];
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			a[i][j] = c[i][j];
}

void da() {
	cout << "Yes\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	n--;
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			cin >> a[i][j];
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			cin >> b[i][j];

	if (eq())
		da();
	rot();
	if (eq())
		da();
	rot();
	if (eq())
		da();
	rot();
	if (eq())
		da();
	rot();
	flip();
	if (eq())
		da();
	rot();
	if (eq())
		da();
	rot();
	if (eq())
		da();
	rot();
	if (eq())
		da();
	rot();
	cout << "No\n";
}