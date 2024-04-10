#include<iostream>

using namespace std;

const int MAXN = 105;

int n, m, cnt;
int minx=1000, miny=1000, maxx, maxy;
char l[MAXN] [MAXN];

int main () {
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> l[i] [j];
			if (l[i] [j]=='B') {
				cnt++;
				minx=min(i, minx);
				miny=min(j, miny);
				maxx=max(i, maxx);
				maxy=max(j, maxy);
			}
		}
	}
	if (cnt==0) {
		cout << 1;
		return 0;
	}
	int d=max(maxx-minx+1, maxy-miny+1);
	if (d>n || d>m) {
		cout << -1;
		return 0;
	}
	cout << d*d-cnt;
	return 0;
}