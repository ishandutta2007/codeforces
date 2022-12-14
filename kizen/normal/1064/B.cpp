#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        int val = 1;
        while(val*2<=N) val<<=1;
        int cnt = 0;
        while(val){
            if(N>=val) ++cnt, N-=val;
            val>>=1;
        }
        int ans = 1;
        while(cnt--) ans<<=1;
        printf("%d\n", ans);
    }
    return 0;
}