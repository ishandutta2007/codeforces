#include<iostream>

using namespace std;

int n;
int l[105] [105];
int sol;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j=x1; j<=x2; j++) {
			for (int k=y1; k<=y2; k++) {
				l[j] [k]++;
			}
		}
	}
	for (int i=1; i<=100; i++) {
		for (int j=1; j<=100; j++) {
			sol+=l[i] [j];
		}
	}
	cout << sol;
	return 0;
}