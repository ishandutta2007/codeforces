#include<iostream>

using namespace std;

int n=10;
char l[15] [15];
int dx[4]={0, 1, 1, 1};
int dy[4]={1, 1, 0, -1};

bool ok (int x, int y) {
	return x>=0 && x<n && y>=0 && y<n;
}

bool go (int x, int y, int d) {
	for (int i=0; i<5; i++) {
		if (!ok(x, y) || l[x] [y]!='X') return 0;
		x+=dx[d];
		y+=dy[d];
	}
	return 1;
}

bool check () {
	int res=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			res+=go(i, j, 0);
			res+=go(i, j, 1);
			res+=go(i, j, 2);
			res+=go(i, j, 3);
		}
	}
	return res;
}

int main () {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> l[i] [j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (l[i] [j]!='.') continue;
			char c=l[i] [j];
			l[i] [j]='X';
			if (check()) {
				cout << "YES";
				return 0;
			}
			l[i] [j]=c;
		}
	}
	cout << "NO";
	return 0;
}