#include <algorithm>
#include <cstdio>
using namespace std;

int endzero(int x){
    int a = 0, b = 0;
    int t = 2;
    while(t <= x) a += x / t, t *= 2;
    t = 5;
    while(t <= x) b += x / t, t *= 5;
    return min(a, b);
}

int n, cnt, start = 1e9;

int main(){
    scanf("%d", &n);
    for(int i = 1; ; i++){
        int c = endzero(i);
        if(c > n) break;
        if(c == n) start = min(start, i), cnt++;
    }
    printf("%d\n", cnt);
    for(int i = start; i < start + cnt; i++) printf("%d ", i);
}