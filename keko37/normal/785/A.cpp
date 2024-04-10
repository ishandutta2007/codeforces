#include<iostream>
#include<map>

using namespace std;

int n, sol;
string s;
map <string, int> m;

int main () {
	m["Tetrahedron"]=4;
	m["Cube"]=6;
	m["Octahedron"]=8;
	m["Dodecahedron"]=12;
	m["Icosahedron"]=20;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s;
		sol+=m[s];
	}
	cout << sol;
	return 0;
}