#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    if (n <= 4 || n%2) {
        printf("0\n");
        return 0;
    }
    int a = n/4;
    if (n%4 == 0) a--;
    printf("%d\n", a);
}