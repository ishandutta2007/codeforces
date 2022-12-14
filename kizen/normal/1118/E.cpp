#include <bits/stdc++.h>

using namespace std;

int main(){
    long long N, k;
    scanf("%lld %lld", &N, &k);
    if(k*(k-1)<N){
        puts("NO"); return 0;
    }
    puts("YES");
    int x = 1, y = 1;
    while(N){
        printf("%d %d\n", x, y<x? y:y+1);
        ++x, ++y, --N;
        if(x>k) x = 1;
        if(y>k-1) y = 1;
    }
    return 0;
}