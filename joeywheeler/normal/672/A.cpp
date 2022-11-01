#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char b[2000];
char c[2000];
int n;

int main() {
    scanf("%d", &n);
    int i = 1;
    while (strlen(b) <= 1005) {
        sprintf(c, "%d", i);
        strcat(b,c);
        i++;
    }
    printf("%c\n", b[n-1]);
}