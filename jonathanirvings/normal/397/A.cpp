#include <bits/stdc++.h>
using namespace std;

bool ada[105];
int a,b,c,d,n;

int main() {
    scanf("%d %d %d",&n,&a,&b);
    --b;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d",&c,&d);
        --d;
        for (int j = c; j <= d; ++j) ada[j] = 1;
    }
    int risan = 0;
    for (int i = a; i <= b; ++i) if (!ada[i]) ++risan;
    printf("%d\n",risan);
}