#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[504][504], brr[504][504];

int main(){
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) scanf("%d", arr[i]+j);
    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) scanf("%d", brr[i]+j);
    for(int i=1;i<=N;++i){
        int cnt = 0;
        for(int j=1;j<=M;++j) cnt += (arr[i][j]!=brr[i][j]);
        if(cnt%2){
            puts("No"); return 0;
        }
    }
    for(int j=1;j<=M;++j){
        int cnt = 0;
        for(int i=1;i<=N;++i) cnt += (arr[i][j]!=brr[i][j]);
        if(cnt%2){
            puts("No"); return 0;
        }
    }
    puts("Yes");
    return 0;
}