#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; scanf("%d", &T);
    while(T--){
        int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%d %d\n", a, a==c? d:c);
    }
    return 0;
}