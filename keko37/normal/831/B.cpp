#include<iostream>

using namespace std;

int n;
string a, b, s, sol;

int main () {
	cin >> a >> b >> s;
	n=s.size();
	for (int i=0; i<n; i++) {
		char c=s[i];
		int velik=0;
		if (c>='A' && c<='Z') {
			velik=1;
			c+='a'-'A';
		}
		if ('0'<=c && c<='9') {
			sol+=c;
			continue;
		}
		int ind=0;
		for (int j=0; j<26; j++) {
			if (a[j]==c) {
				ind=j;
				break;
			}
		}
		char da=b[ind];
		if (velik) da-='a'-'A';
		sol+=da;
	}
	cout << sol;
	return 0;
}