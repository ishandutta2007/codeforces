#include <bits/stdc++.h>

using namespace std;

int N, M;
char arr[1004][1004];
int cnt[1004][1004];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            scanf(" %c", arr[i] + j);
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = M; j >= 1; --j){
            cnt[i][j] = 1;
            if(arr[i][j] == arr[i][j + 1]){
                cnt[i][j] = cnt[i][j + 1] + 1;
            }
        }
    }
    int ans = 0;
    for(int j = 1; j <= M; ++j){
        for(int i = 2; i <= N; ++i){
            if(arr[i][j] == arr[i - 1][j]){
                continue;
            }
            int s = i, e = i, low = cnt[s][j];
            while(arr[s][j] == arr[e + 1][j]){
                ++e; low = min(low, cnt[e][j]);
            }
            if(e == N){
                continue;
            }
            char u = arr[s - 1][j], d = arr[e + 1][j];
            int E = e;
            while(s > 1 && e < N){
                if(arr[s - 1][j] != u || arr[e + 1][j] != d){
                    break;
                }
                --s, ++e;
                low = min(low, min(cnt[s][j], cnt[e][j]));
                if(i - s - 1 == E - i) ans += low;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}