#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int a, b;

int main() {
    scanf("%d %d", &a, &b);
    if (b > a) printf("-1\n");
    else {
        int k = a/b;
        if (k%2==0) k--;
        printf("%.12lf\n", (0.+b+a)/(k+1));
    }
}