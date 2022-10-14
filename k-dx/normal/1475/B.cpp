#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long int ll;

const int N = 0;

int n;

int main () {
	int ttt;
	scanf("%d", &ttt);
	while (ttt--) {
		scanf("%d", &n);

        int x = n / 2020;
        int y = n % 2020;
        if (x >= y) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
		
	}
	return 0;
}