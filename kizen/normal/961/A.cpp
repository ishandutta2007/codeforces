#include <bits/stdc++.h>
using namespace std;
const int NS = 1004;
int N, M;
int cnt[NS];
int main(){
    int i, j, a, f;
    int ans = 0;
    scanf("%d %d", &N, &M);
    for(i=1;i<=M;i++){
        scanf("%d", &a);
        cnt[a]++;
        f = 1;
        for(j=1;j<=N;j++){
            if(cnt[j]==0){
                f = 0;
                break;
            }
        }
        if(f){
            ans++;
            for(j=1;j<=N;j++){
                cnt[j]--;
            }
        }
    }

    printf("%d", ans);

    return 0;
}