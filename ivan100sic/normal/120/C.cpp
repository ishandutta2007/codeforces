#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, k, z=0;
	fin >> n >> k;
	for (int i=0; i<n; i++) {
		int x;
		fin >> x;
		z += x - k*min(3, x/k);
	}
	fout << z << '\n';
}