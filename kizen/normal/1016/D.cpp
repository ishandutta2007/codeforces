#include <bits/stdc++.h>

using namespace std;

int N, M;
int X[104], Y[104], chk[104];
int ans[104][104];

int main(){
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;++i) scanf("%d", X+i);
    for(int i=1;i<=M;++i) scanf("%d", Y+i);
    for(int k=1;;k<<=1){
        int f = 1;
        for(int i=1;i<=N;++i) if(X[i]>=k){
            f = 0; break;
        }
        if(f) break;
        for(int i=0;i<104;++i) chk[i] = 0;
        for(int i=1;i<=N;++i) if(X[i]&k){
            int did = 0;
            for(int j=1;j<=M;++j) if(!chk[j]&&(Y[j]&k)){
                did = 1, chk[j] = 1;
                ans[i][j]|=k;
                break;
            }
            if(!did) ans[i][1]|=k;
        }
    }
    for(int k=1;;k<<=1){
        int f = 1;
        for(int j=1;j<=M;++j) if(Y[j]>=k){
            f = 0; break;
        }
        if(f) break;
        for(int j=0;j<104;++j) chk[j] = 0;
        for(int j=1;j<=M;++j) if(Y[j]&k){
            int did = 0;
            for(int i=1;i<=N;++i) if(!chk[i]&&(X[i]&k)){
                did = 1, chk[i] = 1;
                ans[i][j]|=k;
                break;
            }
            if(!did) ans[1][j]|=k;
        }
    }

    for(int i=1;i<=N;++i){
        int val = 0;
        for(int j=1;j<=M;++j) val ^= ans[i][j];
        if(val!=X[i]){
            puts("NO");
            return 0;
        }
    }
    for(int j=1;j<=M;++j){
        int val = 0;
        for(int i=1;i<=N;++i) val ^= ans[i][j];
        if(val!=Y[j]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j) printf("%d ", ans[i][j]);
        puts("");
    }

    return 0;
}