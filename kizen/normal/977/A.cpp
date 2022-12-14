#include <bits/stdc++.h>
using namespace std;

int N, k;

int main(){
    scanf("%d %d", &N, &k);
    while(k--){
        if(N%10==0) N/=10;
        else N--;
    }

    printf("%d", N);

    return 0;
}