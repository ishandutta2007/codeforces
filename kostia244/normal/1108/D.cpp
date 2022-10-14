#include <bits/stdc++.h>
using namespace std;


int n, dc = 0, an = 0;
string a = "BGR", s;
int ed[6] = {0, };


int main() {
	cin >> n;
	cin >> s;
	s += "   ";
	for(int i = 0; i < (n - 1); i++) {
		if(s[i] == s[i + 1]) {
			int j = 0;
			while(a[j] == s[i] || a[j] == s[i + 2])
				j++;
			an++;
			s[i + 1] = a[j];
		}
	}
	cout << an << "\n";
	cout << s.substr(0, n);
}