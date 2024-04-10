#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int c; char l;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        char t; scanf(" %c", &t);
        if (c == 0) l = t;
        if (t == l) c++;
        else c--;
    }
    printf("%d\n", c);
}