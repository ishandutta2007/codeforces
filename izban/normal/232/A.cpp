#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <assert.h>

using namespace std;

#define ll long long

int n = 100, k;
int a[101][101];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> k;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (k >= j-1) {
				a[i][j] = a[j][i] = 1;
				k -= j-1;
			}
		}
	}

	printf("%d\n", n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d", a[i][j]);
		printf("\n");
	}
	return 0;
}