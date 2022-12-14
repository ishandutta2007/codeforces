#include <bits/stdc++.h>

using namespace std;

int N;
int cnt[1004], ans[24][24];

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N*N;++i){
        int a; scanf("%d", &a), ++cnt[a];
    }
    if(N%2==0){
        int x = 1, y = 1;
        for(int i=1;i<=1000;++i) if(cnt[i]){
            if(cnt[i]%4!=0){
                puts("NO"); return 0;
            }
            ans[x][y] = i; cnt[i] -= 4; --i; ++y;
            if(y>N/2) ++x, y = 1;
        }
        puts("YES");
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                if(i<=N/2&&j<=N/2) printf("%d ", ans[i][j]);
                else if(i<=N/2&&j>N/2) printf("%d ", ans[i][N-j+1]);
                else if(i>N/2&&j<=N/2) printf("%d ", ans[N-i+1][j]);
                else printf("%d ", ans[N-i+1][N-j+1]);
            }
            puts("");
        }
    }
    else{
        int x = 1, y = 1, X = 1, Y = 1;
        for(int i=1;i<=1000;++i) if(cnt[i]){
            if(cnt[i]%2==1&&ans[N/2+1][N/2+1]==0) ans[N/2+1][N/2+1] = i, --cnt[i];
            else if((cnt[i]%4==2||(cnt[i]%4==0&&x==N/2+1))&&(X<=N/2||Y<=N/2)){
                if(X<=N/2) ans[X++][N/2+1] = i, cnt[i]-=2;
                else ans[N/2+1][Y++] = i, cnt[i] -= 2;
            }
            else if(cnt[i]%4==0){
                ans[x][y] = i; cnt[i] -= 4;
                ++y;
                if(y>N/2) ++x, y = 1;
            }
            else{
                puts("NO"); return 0;
            }
            --i;
        }
        puts("YES");
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                if(i<=N/2&&j<=N/2) printf("%d ", ans[i][j]);
                else if(i<=N/2&&j>N/2+1) printf("%d ", ans[i][N-j+1]);
                else if(i>N/2+1&&j<=N/2) printf("%d ", ans[N-i+1][j]);
                else if(i>N/2+1&&j>N/2+1) printf("%d ", ans[N-i+1][N-j+1]);
                else if(j==N/2+1&&i==N/2+1) printf("%d ", ans[i][j]);
                else if(i<N/2+1||j<N/2+1) printf("%d ", ans[i][j]);
                else if(i>N/2+1) printf("%d ", ans[N-i+1][j]);
                else printf("%d ", ans[i][N-j+1]);
            }
            puts("");
        }
    }
    return 0;
}