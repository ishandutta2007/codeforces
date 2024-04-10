#include <bits/stdc++.h>
using namespace std;


int n;

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

        int zer = 0;
        bool bylo = false;
        int wynik = 0;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            if (a == 1) bylo = true;

            if (bylo and a == 1) {
                wynik += zer;
                zer = 0;
            }

            if (bylo and a == 0) {
                zer++;
            }
        }

		printf("%d\n", wynik);
		
	}
	return 0;
}