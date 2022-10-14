#include<iostream>

using namespace std;

int n, m, nn;
int l[105] [4];

int main () {
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		if (i<=2*n) {
			if (i%2==0) l[(i-1)/2] [3]=i;
			if (i%2==1) l[(i-1)/2] [0]=i;
		} else {
			if (i%2==0) l[(i-1-2*n)/2] [2]=i;
			if (i%2==1) l[(i-1-2*n)/2] [1]=i;
		}
	}
	int cnt=0;
	for (int i=0; i<4*n; i++) {
		if (cnt==m) break;
		if (i%4==0) nn=l[i/4] [1];
		if (i%4==1) nn=l[i/4] [0];
		if (i%4==2) nn=l[i/4] [2];
		if (i%4==3) nn=l[i/4] [3];
		if (nn) cout << nn << " ";
		if (nn) cnt++;
	}
	return 0;
}