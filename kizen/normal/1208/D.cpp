#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL NS = (LL)2e5 + 4;
LL N;
LL arr[NS], ans[NS];
LL tree[NS];

void push(LL pos, LL val){
    while(pos < NS){
        tree[pos] += val;
        pos += (pos & -pos);
    }
}

LL getval(LL pos){
    LL rv = 0;
    while(pos){
        rv += tree[pos];
        pos -= (pos & -pos);
    }
    return rv;
}

int main(){
    scanf("%lld", &N);
    for(LL i = 1; i <= N; ++i){
        scanf("%lld", arr + i);
        push(i + 1, i);
    }
    for(LL i = N; i >= 1; --i){
        LL a = 0, b = N - 1, mid;
        while(a < b){
            mid = (a + b) / 2 + 1;
            LL gap = getval(mid + 1);
            if(gap <= arr[i]) a = mid;
            else b = mid - 1;
        }
        ++a;
        ans[i] = a;
        push(a + 1, -a);
    }
    for(LL i = 1; i <= N; ++i){
        printf("%lld ", ans[i]);
    }
    puts("");
    return 0;
}