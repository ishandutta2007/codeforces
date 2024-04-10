#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100][100], b[100][100];

void swap(int i, int j) {
	int t = a[i][j];
	a[i][j] = b[i][j];
	b[i][j] = t;
}

int main () {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &b[i][j]);
		}
	}

	//rows
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m-1; j++) {
			if(a[i][j] >= a[i][j+1] or b[i][j] >= b[i][j+1]) {
				swap(i, j+1);
			}
			if(a[i][j] >= a[i][j+1] or b[i][j] >= b[i][j+1]) {
				printf("Impossible\n");
				return 0;
			}
		}
	}

	//columns
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] >= a[i+1][j] or b[i][j] >= b[i+1][j]) {
				swap(i+1, j);
			}
			if(a[i][j] >= a[i+1][j] or b[i][j] >= b[i+1][j]) {
				printf("Impossible\n");
				return 0;
			}
		}
	}
	
	printf("Possible\n");

	return 0;
}