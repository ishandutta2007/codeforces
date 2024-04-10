#include <bits/stdc++.h>
using namespace std;
char idk[2000][2000];
bool fail[2000];
bool succ;
int main() {
	int n, p,i,j;
	string s;
	scanf("%d%d", &n, &p);
	cin >> s;
	for (i = 0; i < n; i++) {
		idk[i / p][i%p] = s[i];
	}
	for (i = 0; i < p; i++) {
		int num = 0, a = 0, b = 0;
		for (j = 0; j*p + i < n;j++) {
			if (idk[j][i] == '.')num++;
			if (idk[j][i] == '0')a = 1;
			if (idk[j][i] == '1')b = 1;
		}
		if (num + a + b >= 2)fail[i] = 1;
		char tar=0;
		if (a)tar = '1';
		if (b)tar = '0';
		for (j = 0; j*p + i<n; j++) {
			if (idk[j][i] != '.')continue;
			if (tar != 0)idk[j][i] = tar;
			else {
				idk[j][i] = '0';
				tar = '1';
			}
		}
	}
	bool suc = 0;
	for (i = 0; i < p; i++)if (fail[i])suc = 1;
	if (suc==0) {
		printf("No"); return 0;
	}
	for (i = 0; i < n; i++)printf("%c", idk[i / p][i%p]);
}