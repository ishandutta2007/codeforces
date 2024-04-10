#include<iostream>

using namespace std;

int sol;
char l[10] [10];
int dx[4]={0, 1, 1, 1};
int dy[4]={1, 1, 0, -1};

bool ok (int xx, int yy) {
	return xx>=0 && xx<=3 && yy>=0 && yy<=3;
}

int kol (int x, int y, int d) {
	int res=0;
	for (int i=0; i<3; i++) {
		if (ok(x, y) && l[x] [y]=='x') res++;
		x+=dx[d];
		y+=dy[d];
	}
	return res;
}

int pro () {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (kol(i, j, 0)==3 || kol(i, j, 1)==3 || kol(i, j, 2)==3 || kol(i, j, 3)==3) return 1;
		}
	}
	return 0;
}

int main () {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			cin >> l[i] [j];
		}
	}
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (l[i] [j]=='.') {
				l[i] [j]='x';
				sol=max(sol, pro());
				l[i] [j]='.';
			}
		}
	}
	if (sol==1) cout << "YES"; else cout << "NO";
	return 0;
}