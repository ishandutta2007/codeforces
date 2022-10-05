#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int c[3] = {};
    for(int x; n--; ){
        scanf("%d", &x);
        c[x]++;
    }
    if(c[2]){ printf("2 "); c[2]--; }
    if(c[1]){ printf("1 "); c[1]--; }
    while(c[2]){ printf("2 "); c[2]--; }
    while(c[1]){ printf("1 "); c[1]--; }
}