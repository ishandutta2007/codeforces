#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, A, B, C;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &A, &B, &C);
        C %= 3;
        if(!C) printf("%d\n", A);
        else if(C == 1) printf("%d\n", B);
        else printf("%d\n", A ^ B);
    }
    return 0;
}