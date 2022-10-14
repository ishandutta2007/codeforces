#include<bits/stdc++.h>

using namespace std;

int n, k, sol = 10000000;
int l[30];
string s;

int main () {
	cin >> n >> k >> s;
	for (int i=0; i<n; i++) {
		l[s[i] - 'A']++;
	}
	for (int i=0; i<k; i++) {
		sol = min(sol, l[i]);
	}
	cout << sol * k;
	return 0;
}