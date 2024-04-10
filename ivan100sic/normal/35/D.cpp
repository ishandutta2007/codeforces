#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, x;
int c[105], d[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> n >> x;
	for (int i=0; i<n; i++) {
		fin >> c[i];
		d[i] = (n-i)*c[i];
	}
	sort(d, d+n);
	int z = 0;
	for (int i=0; i<n; i++) {
		if (x >= d[i]) {
			x -= d[i];
			z++;
		}
	}
	fout << z << '\n';

}