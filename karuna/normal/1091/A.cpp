#include <bits/stdc++.h>

int min(int a, int b){
    return a>b?b:a;
}
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int mn = min(min(a+2, b+1), c);

    if (mn == a+2) printf("%d", 3*a+3);
    else if (mn == b+1) printf("%d", 3*b);
    else if (mn == c) printf("%d", 3*c-3);
}