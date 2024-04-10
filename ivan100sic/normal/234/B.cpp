#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[10005];
int b[10005];

bool cmp(int i, int j) {
	return a[i] > a[j];
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, k;
	fin >> n >> k;
	for (int i=1; i<=n; i++)
		fin >> a[i];
	iota(b, b+n, 1);
	sort(b, b+n, cmp);
	fout << a[b[k-1]] << '\n';
	for (int i=0; i<k; i++)
		fout << b[i] << ' ';
	fout << '\n';

}