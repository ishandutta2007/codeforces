#include <bits/stdc++.h>
using namespace std;

int n;
string s,t;

void solve() {
    cin >> n >> s >> t;
    int ndsp[n];
    int idx = 0;
    for (int i = 0; i < n; i++){
        if (s[i] != t[i]) {ndsp[idx] = i; idx++;}
    }
    if (idx != 2 && idx != 0) cout << "NO" << endl;
    else if (idx == 2 && (t[ndsp[0]] != t[ndsp[1]] || s[ndsp[1]] != s[ndsp[0]])) cout << "NO" << endl;
    else cout << "YES" << endl;
    
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
}