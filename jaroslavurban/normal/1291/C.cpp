#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

int main(){
	int t;
	std::cin >> t;
	long long arr[4000];
	for (int i = 0; i < t; i++){
		int n, m, k;
		long long mymax = 0;
		std::cin >> n >> m >> k;
		k = m - 1 < k ? m - 1 : k;
		m = m - k - 1;
		for (int i = 0; i < n; i++)
			std::cin >> arr[i];

		for (int i = 0; i < k + 1; i++){
			int l = i;
			int r = k - i;

			long long min = 10e10;
			for (int j = 0; j < m + 1; j++){
				int ll = l + j;
				int rr = r + m - j;

				// printf("n %d ll %d rr %d\n", n, ll, rr);
				long long max = arr[ll] > arr[n - rr - 1] ? arr[ll] : arr[n - rr - 1];
				if (max < min)
					min = max;
			}
			if (min > mymax)
				mymax = min;
		}
		std::cout << mymax << '\n';
	}
}