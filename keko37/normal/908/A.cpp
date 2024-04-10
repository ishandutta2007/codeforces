#include<iostream>

using namespace std;

int n, sol;
string s;

int main () {
	cin >> s;
	n=s.size();
	for (int i=0; i<n; i++) {
		if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') sol++;
		if ('0'<=s[i] && s[i]<='9' && s[i]%2==1) sol++;
	}
	cout << sol;
	return 0;
}