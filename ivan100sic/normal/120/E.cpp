#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int t;
	fin >> t;
	while (t--) {
		int x;
		fin >> x;
		fout << (x+1)%2 << '\n';
	}	
	
}