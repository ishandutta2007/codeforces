#include <bits/stdc++.h>
using namespace std;

const int N = 0;

int n;

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

        int sum = 0;
        for (int i = 1; i <= 9; i++) {
            int num = 0;
            int j = 0;

            while (num <= 1000 and num != n) {
                num = num * 10 + i;
                sum += j;

                //printf("%d\n", num);

                j++;
            }

            sum += j;
            if (num == n) break;

        }
        //printf("---\n");
        printf("%d\n", sum);
	}

	return 0;
}