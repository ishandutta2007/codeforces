#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    scanf("%d", &N);
    if(N%3==0){
        printf("%d %d %d", 1, 1, N-2);
    }
    else if(N%3==1){
        printf("%d %d %d", 1, 2, N-3);
    }
    else if(N%3==2){
        printf("%d %d %d", 2, 2, N-4);
    }
    return 0;
}