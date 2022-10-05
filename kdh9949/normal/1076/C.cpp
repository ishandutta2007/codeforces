#include <bits/stdc++.h>
using namespace std;

int n, d;

int main(){
    scanf("%d", &n);
    for(; n--; ){
        scanf("%d", &d);
        if(1<=d&&d<=3){ puts("N"); continue; }
        double a=(d+sqrt(d*d-4*d))/2;
        double b=d-a;
        printf("Y %.12f %.12f\n", a, b);
    }
}