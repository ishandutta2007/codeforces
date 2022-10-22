#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	int n, i, j;
	scanf("%d", &n);

	int arr[100000];
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	int cpy[100000];
	for (i = 0; i < n; i++) {
		cpy[i] = arr[i];
	}

	int rotcnt = 0;
	int temp = 1;

	for (i = 0; i < n-1; i++) {
		if (arr[i] == arr[i + 1]) {
			temp++;
		}
		else {
			if (temp > rotcnt) rotcnt = temp;
			temp = 1;
		}
	}


	for (i = 0; i < n; i++) {
		int rotnum = i - rotcnt >= 0 ? i - rotcnt : n + i - rotcnt;
		arr[rotnum] = cpy[i];
	}

	int cnt = 0;

	for (i = 0; i < n; i++) {
		if (arr[i] > cpy[i]) {
			cnt++;
		}
	}


	printf("%d", cnt);
}