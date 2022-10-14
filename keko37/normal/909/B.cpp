#include<iostream>

using namespace std;

const int MAXN = 5055;

int n, sol;
int l[MAXN];

int main () {
	cin >> n;
	int lim=n*(n+1)/2;
	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			for (int k=1; k<=lim; k++) {
				if (l[k]<i) {
					l[k]=j;
					break;
				}
			}
		}
	}
	for (int i=1; i<=lim; i++) {
		if (l[i]) sol++;
	}
	cout << sol;
	return 0;
}