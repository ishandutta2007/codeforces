#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, N;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        printf("%d\n", N/7+((N%7)>=1));
    }
    return 0;
}