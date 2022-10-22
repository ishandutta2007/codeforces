#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, m = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++){
	    if (i == n || s[i] > s[i+1]) {m = i; break;}
	}
	for (int i = 0; i < n; i++){
	    if (i == m) continue;
	    cout << s[i];
	}
}