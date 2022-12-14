#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, x, y, z;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z);
    if(a>x){
        puts("NO"); return 0;
    }
    x -= a;
    if(b>x+y){
        puts("NO"); return 0;
    }
    z += x+y-b;
    if(c>z){
        puts("NO"); return 0;
    }
    puts("YES");
    return 0;
}