#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int odd = n-1;
    while (odd%2 == 0) odd--;
    for (int i = odd; i >= 1; i -= 2) printf("%d ", n-i);
    for (int i = 1; i <= odd; i += 2) printf("%d ", n-i);

    int even = n-1;
    while (even%2 == 1) even--;
    for (int i = even; i >= 2; i -= 2) printf("%d ", n-i);
    printf("%d ", n);
    for (int i = 2; i <= even; i += 2) printf("%d ", n-i);
    printf("%d ", n);
    printf("\n");
}