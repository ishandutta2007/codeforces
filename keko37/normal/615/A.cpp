#include<iostream>

using namespace std;

int n, m;
int p[105];

int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		for (int j=0; j<x; j++) {
			int y;
			cin >> y;
			p[y]=1;
		}
	}
	for (int i=1; i<=m; i++) {
		if (p[i]==0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}