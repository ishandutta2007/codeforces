#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int n, m;
int tip[MAXN], a[MAXN], b[MAXN];
int p[MAXN], sol[MAXN];

int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> tip[i] >> a[i] >> b[i];
		a[i]--; b[i]--;
		if (tip[i] == 1) {
			for (int j=a[i]; j<b[i]; j++) {
				p[j] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i=n-1; i>=0; i--) {
		cnt++;
		if (p[i] == 1) cnt--;
		sol[i] = cnt;
	}
	for (int i=0; i<m; i++) {
		if (tip[i] == 1) continue;
		int br = 0;
		for (int j=a[i]; j<b[i]; j++) {
			if (sol[j] > sol[j+1]) br++;
		}
		if (br == 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES" << endl;
	for (int i=0; i<n; i++) {
		cout << sol[i] << " ";
	}
	return 0;
}