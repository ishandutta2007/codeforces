#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	string s; cin >> s;
	int ans = 0;
	for (int i = 1; i < n; i++){
	    if (s[i] == s[i-1]){
	        ans ++;
	        if (s[i-1] != 'R' && (i == n-1 || s[i+1] != 'R')) s[i] = 'R';
	        if (s[i-1] != 'B' && (i == n-1 || s[i+1] != 'B')) s[i] = 'B';
	        if (s[i-1] != 'G' && (i == n-1 || s[i+1] != 'G')) s[i] = 'G';
	    }
	}
	cout << ans << endl << s;
}