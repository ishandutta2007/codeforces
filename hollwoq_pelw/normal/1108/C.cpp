#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	string s; cin >> s;
	string gen[] = {"RBG", "RGB", "BGR", "BRG", "GRB", "GBR"};
	int ans = INT_MAX, c = 0, r = 0;
	for (int i = 0; i < 6; i++){
	    for (int j = 0; j < n; j++) if (s[j] != gen[i][j%3]) c++;
	    if (ans > c) {ans = c; r = i;}
	    c = 0;
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) cout << gen[r][i%3]; 
}