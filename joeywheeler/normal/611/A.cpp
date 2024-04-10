#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int a[7] = {52, 52, 52, 52, 53, 53, 52};
int b[12] = {30, 30, 30, 30, 29, 31, 31, 31, 31, 31, 31, 31};

char buf[100];

int main() {
    int x; scanf("%d %*s %s", &x, buf);
    if (buf[0] == 'w') {
        printf("%d\n", a[x-1]);
    } else {
        int c = 0;
        FO(i,0,12) if (b[i] >= x) c++;
        printf("%d\n", c);
    }
}