#include<iostream>

using namespace std;

int n;
int l[105];

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	int start=l[0];
	while (1) {
		int naj=0;
		for (int i=0; i<n; i++) {
			naj=max(naj, l[i]);
		}
		int naji=n-1;
		for (int i=n-1; i>=0; i--) {
			if (l[i]==naj) {
				naji=i;
				break;
			}
		}
		if (naji==0) {
			cout << l[0]-start;
			break;
		} else {
			l[naji]--;
			l[0]++;
		}
	}
	return 0;
}