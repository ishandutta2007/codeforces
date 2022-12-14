#include <bits/stdc++.h>

using namespace std;

using LL = long long;
LL N;
LL far[204][204], gap[204][204];
vector < LL > arr;

int main(){
    for(LL i = 0; i < 204; ++i){
        for(LL j = 0; j < 204; ++j){
            far[i][j] = gap[i][j] = (LL)1e18;
        }
    }
    scanf("%lld", &N);
    while(N--){
        LL num; scanf("%lld", &num); if(num) arr.push_back(num);
        if((int)arr.size() > 200){
            puts("3"); return 0;
        }
    }
    for(int i = 0; i < (int)arr.size(); ++i){
        for(int j = 0; j < (int)arr.size(); ++j){
            if(arr[i] & arr[j]) gap[i][j] = far[i][j] = 1;
        }
    }
    LL ans = (LL)1e18;
    for(LL k = 0; k < (int)arr.size(); ++k){
        for(LL i = 0; i < (int)arr.size(); ++i){
            for(LL j = 0; j < (int)arr.size(); ++j){
                if(i != j && j != k && k != i){
                    ans = min(ans, gap[k][i] + gap[k][j] + far[i][j]);
                    far[i][j] = min(far[i][j], far[i][k] + far[k][j]);
                }
            }
        }
    }
    printf("%lld\n", ans == (LL)1e18 ? -1 : ans);
    return 0;
}