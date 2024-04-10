#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL NS = (LL)1e5 + 4;
LL N;
LL arr[NS];
LL d[NS][3];

int main(){
    scanf("%lld", &N);
    for(LL i = 1; i <= N; ++i){
        scanf("%lld", arr + i);
        d[i][1] = min(d[i - 1][2] + abs(arr[i] + 1), d[i - 1][1] + abs(arr[i] - 1));
        d[i][2] = min(d[i - 1][1] + abs(arr[i] + 1), d[i - 1][2] + abs(arr[i] - 1));
        if(i == 1) d[i][1] = abs(arr[i] + 1), d[i][2] = abs(arr[i] - 1);
    }
    printf("%lld\n", d[N][2]);
    return 0;
}