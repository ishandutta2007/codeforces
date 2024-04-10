#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[104][104], B[104][104];

int main(){
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j){
        char c;
        scanf(" %c", &c);
        if(c=='*') A[i][j] = 1;
    }

    int cnt = 0;
    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) if(A[i][j]){
        int x;
        for(x=0;;++x){
            if(!A[i-x][j]||!A[i+x][j]||!A[i][j-x]||!A[i][j+x]) break;
        }
        --x;
        if(x){
            ++cnt;
            for(int k=0;k<=x;++k){
                B[i-k][j] = B[i+k][j] = B[i][j-k] = B[i][j+k] = 1;
            }
        }
    }

    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) if(A[i][j]!=B[i][j]){
        puts("-1");
        return 0;
    }

    printf("%d\n", cnt);
    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) if(A[i][j]){
        int x;
        for(x=0;;++x){
            if(!A[i-x][j]||!A[i+x][j]||!A[i][j-x]||!A[i][j+x]) break;
        }
        --x;
        if(x) printf("%d %d %d\n", i, j, x);
    }

    return 0;
}