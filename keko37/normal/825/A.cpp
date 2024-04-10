#include<iostream>

using namespace std;

int n;
string s;

int main () {
	cin >> n >> s;
	s='0'+s+'0';
	n+=2;
	for (int i=0; i<n; i++) {
		if (s[i]=='1') continue;
		for (int j=i+1; j<n; j++) {
			if (s[j]=='0') {
				cout << j-i-1;
				break;
			}
		}
	}
	return 0;
}