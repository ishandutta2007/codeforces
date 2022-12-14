#include <bits/stdc++.h>
using namespace std;

int N, k;
int arr[10][104];

int main(){
    scanf("%d %d", &N, &k);
    puts("YES");
    if(k%2){
        for(int i=2;i<=3;i++){
            for(int j=N/2;j>=2;j--){
                if(k>=2){
                    arr[i][j] = arr[i][N-j+1] = 1;
                    k-=2;
                }
            }
        }
        if(k>=1) arr[2][N/2+1] = 1;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=N;j++){
                arr[i][j]==1? printf("#"):printf(".");
            }
            puts("");
        }
    }
    else{
        for(int i=1;i<=4;i++){
            for(int j=1;j<=N;j++){
                if(i>1&&i<4&&j>1&&j<N&&j-1<=k/2){
                    printf("#");
                }
                else printf(".");
            }
            puts("");
        }
    }

    return 0;
}