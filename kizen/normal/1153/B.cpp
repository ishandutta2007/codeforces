#include <bits/stdc++.h>

using namespace std;

int N, M, H;
int ans[104][104];

int main(){
    scanf("%d %d %d", &N, &M, &H);
    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) ans[i][j] = (int)1e9;
    for(int j=1;j<=M;++j){
        int num; scanf("%d", &num);
        for(int i=1;i<=N;++i) ans[i][j] = min(ans[i][j], num);
    }
    for(int i=1;i<=N;++i){
        int num; scanf("%d", &num);
        for(int j=1;j<=M;++j) ans[i][j] = min(ans[i][j], num);
    }
    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j){
        int num; scanf("%d", &num);
        if(!num) ans[i][j] = 0;
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
    return 0;
}