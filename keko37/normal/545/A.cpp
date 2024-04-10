#include<iostream>

using namespace std;

int n;
int l[105] [105];
int p[105];

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> l[i] [j];
			if (l[i] [j]==-1) continue;
			if (l[i] [j]==1) {
				p[i]++;
			} else if (l[i] [j]==2) {
				p[j]++;
			} else if (l[i] [j]==3) {
				p[i]++;
				p[j]++;
			}
		}
	}
	int cnt=0;
	for (int i=0; i<n; i++) {
		if (p[i]==0) cnt++;
	}
	cout << cnt << endl;
	for (int i=0; i<n; i++) {
		if (p[i]==0) cout << i+1 << " ";
	}
	return 0;
}