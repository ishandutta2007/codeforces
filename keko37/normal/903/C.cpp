#include<iostream>
#include<map>

using namespace std;

int n, sol;
map <int, int> m;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		m[x]++;
		sol=max(sol, m[x]);
	}
	cout << sol;
	return 0;
}