#include<iostream>

using namespace std;

int n;
string s;

int main () {
	cin >> s;
	n=s.size();
	for (int i=0; i<(n+1)/2; i++) {
		int j=n-i-1;
		if (s[i]==s[j]) {
			if (!(s[i]=='A' || s[i]=='H' || s[i]=='I' || s[i]=='M' || s[i]=='O' || s[i]=='T' || s[i]=='U' || s[i]=='V' || s[i]=='W' || s[i]=='X' || s[i]=='w' || s[i]=='x' || s[i]=='v' || s[i]=='o' || s[i]=='Y')) {
				cout << "NIE";
				return 0;
			}
		} else {
			if (!((s[i]=='b' && s[j]=='d') || (s[i]=='d' && s[j]=='b') || (s[i]=='p' && s[j]=='q') || (s[i]=='q' && s[j]=='p'))) {
				cout << "NIE";
				return 0;
			}
		}
	}
	cout << "TAK";
	return 0;
}