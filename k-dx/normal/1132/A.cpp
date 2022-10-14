#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if(a == d and a != 0) printf("1\n");
    else if(a == 0 and c == 0 and d == 0) printf("1\n");
    else printf("0\n");

    return 0;
}