#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL arr[(LL)1e7+4], N;
LL Q, L, R;

void push(LL val, LL T){
    if(val) arr[++N] = val;
    if(val==999){
        int g=  1;
    }
    if(val<(LL)1e17){
        if(T){
            for(LL i=1;i<10;++i) push(val*10+i, T-1);
        }
        if(val) push(val*10, T);
    }
}

int main(){;
    push(0, 3);
    arr[++N] = (LL)1e18;
    sort(arr+1, arr+N+1);
    scanf("%lld", &Q);
    while(Q--){
        scanf("%lld %lld", &L, &R);
        printf("%lld\n", (long long)(upper_bound(arr+1, arr+N+1, R)-lower_bound(arr+1, arr+N+1, L)));
    }

    return 0;
}