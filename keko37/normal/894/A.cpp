#include<iostream>

using namespace std;

int n, sol;
string s;

int main () {
	cin >> s;
	n=s.size();
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int k=j+1; k<n; k++) {
				if (s[i]=='Q' && s[j]=='A' && s[k]=='Q') sol++;
			}
		}
	}
	cout << sol;
	return 0;
}