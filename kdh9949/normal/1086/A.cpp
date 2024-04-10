#include <bits/stdc++.h>
using namespace std;

int x[3], y[3], ax, ay, d = 100000;

int f(int a, int b){
    int r = 0;
    for(int i = 0; i < 3; i++) r += abs(x[i] - a) + abs(y[i] - b);
    return r;
}

void g(int x, int y){
    if(x == ax && y == ay) return;
    printf("%d %d\n", x, y);
    if(x < ax) g(x + 1, y);
    else if(x > ax) g(x - 1, y);
    else if(y < ay) g(x, y + 1);
    else g(x, y - 1);
}

int main(){
    for(int i = 0; i < 3; i++) scanf("%d%d", x + i, y + i);
    for(int i = 0; i <= 1000; i++) for(int j = 0; j <= 1000; j++){
        if(d > f(i, j)){
            d = f(i, j);
            ax = i;
            ay = j;
        }
    }
    printf("%d\n%d %d\n", d + 1, ax, ay);
    for(int i = 0; i < 3; i++) g(x[i], y[i]);
}