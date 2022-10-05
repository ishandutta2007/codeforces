#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, s, d[N], c;

int main(){
    scanf("%d%d", &n, &s);
    for(int i = 0, x, y; i < n - 1; i++){
        scanf("%d%d", &x, &y);
        d[x]++; d[y]++;
    }
    c = count(d + 1, d + n + 1, 1);
    printf("%.12f\n", 2.0 * s / c);
}