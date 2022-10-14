#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 2005;

int n, m, k, cnt, sol;
char l[MAXN] [MAXN];

int main () {
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			while (1) {
				l[i] [j]=getchar();
				if (l[i] [j]=='.' || l[i] [j]=='*') break;
			}
			if (l[i] [j]=='.') cnt++;
		}
	}
	if (k==1) {
		cout << cnt;
		return 0;
	}
	for (int i=0; i<n; i++) {
		int br=0;
		for (int j=0; j<m; j++) {
			if (l[i] [j]=='.') br++; else br=0;
			if (br>=k) sol++;
		}
	}
	for (int i=0; i<m; i++) {
		int br=0;
		for (int j=0; j<n; j++) {
			if (l[j] [i]=='.') br++; else br=0;
			if (br>=k) sol++;
		}
	}
	cout << sol;
	return 0;
}