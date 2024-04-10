#include<iostream>

using namespace std;

int n, sol=1000000;
int l[300];
string s;


int main () {
	cin >> s;
	n=s.size();
	for (int i=0; i<n; i++) {
		l[s[i]]++;
	}
	sol=min(sol, l['B']);
	sol=min(sol, l['u']/2);
	sol=min(sol, l['l']);
	sol=min(sol, l['b']);
	sol=min(sol, l['a']/2);
	sol=min(sol, l['s']);
	sol=min(sol, l['r']);
	cout << sol;
	return 0;
}