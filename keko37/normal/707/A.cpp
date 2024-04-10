#include<iostream>

using namespace std;

int n, m, sol=1;
char l[105] [105];

int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> l[i] [j];
			if (l[i] [j]=='C' || l[i] [j]=='M' || l[i] [j]=='Y') sol=0;
		}
	}
	if (sol) {
		cout << "#Black&White";
	} else {
		cout << "#Color";
	}
	return 0;
}