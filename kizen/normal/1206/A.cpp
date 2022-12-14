#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[104], B[104];

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d", A + i);
    }
    scanf("%d", &M);
    for(int i = 1; i <= M; ++i){
        scanf("%d", B + i);
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            int val = A[i] + B[j], f = 1;
            for(int x = 1; x <= N; ++x){
                if(A[x] == val) f = 0;
            }
            for(int x = 1; x <= M; ++x){
                if(B[x] == val) f = 0;
            }
            if(f){
                printf("%d %d\n", A[i], B[j]); return 0;
            }
        }
    }
    return 0;
}