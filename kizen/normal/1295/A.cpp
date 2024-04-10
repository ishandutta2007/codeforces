#include <bits/stdc++.h>

using namespace std;

int T;
int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    scanf("%d", &T);
    while(T--){
        int N; scanf("%d", &N);
        if(N % 2){
            printf("7");
            N -= 3;
        }
        while(N){
            printf("1");
            N -= 2;
        }
        puts("");
    }
    return 0;
}