#include <stdio.h>
#include <string.h>
#include <math.h>

int arr[100000][2];
int arr2[100000] = { 1 };

int min(int a, int b) {
	return a > b ? b : a;
}

int max(int a, int b) {
	return a > b ? a : b;
}
int min_max(int c, int i) {
	if (c == 1) {
		return arr[i][0] > arr[i][1] ? arr[i][0] : arr[i][1];
	}
	else return arr[i][0] > arr[i][1] ? arr[i][1] : arr[i][0];
}


int main() {

	int n , m = 0, i, j, k;
	int temp;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	for (i = 1; i < n; i++) {
		if (max(arr[i][0], arr[i][1]) <= min_max(arr2[i - 1], i - 1)) {
			arr2[i] = 1;
		}
		else if (min(arr[i][0], arr[i][1]) <= min_max(arr2[i - 1], i - 1)) {
			arr2[i] = 0;
		}
		else {
			m = 1;
			break;
		}
	}

	if (m == 1) {
		printf("NO");
	}
	else printf("YES");

	
}