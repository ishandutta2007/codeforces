#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	string s;
	int a;
	fin >> s >> a;

	if ((s == "front") == (a == 1))
		fout << "L\n";
	else
		fout << "R\n";
}