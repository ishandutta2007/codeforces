#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 1005;

int n, m, c, p;
int l[MAXN];

bool ok () {
	for (int i=0; i<n; i++) {
		if (l[i]==0) return 0;
	}
	return 1;
}

int main () {
	cin >> n >> m >> c;
	for (int i=0; i<m; i++) {
		if (ok()) break;
		cin >> p;
		if (p<=c/2) {
			for (int j=0; j<n; j++) {
				if (l[j]==0 || p<l[j]) {
					l[j]=p;
					cout << j+1 << endl;
					fflush(stdout);
					break;
				}
			}
		} else {
			for (int j=n-1; j>=0; j--) {
				if (l[j]==0 || p>l[j]) {
					l[j]=p;
					cout << j+1 << endl;
					fflush(stdout);
					break;
				}
			}
		}
	}
	return 0;
}