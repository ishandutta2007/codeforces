#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        if(c<a) printf("%d\n", c);
        else{
            printf("%d\n", b/c*c+c);
        }
    }
    return 0;
}