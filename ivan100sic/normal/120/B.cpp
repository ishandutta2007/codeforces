#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[1005];

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> n >> k;
	for (int i=0; i<n; i++)
		fin >> a[i];
	k--;
	while (!a[k])
		k = (k+1) % n;
	fout << k+1 << '\n';
}