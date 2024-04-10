#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, m, k;

bool can(ll t){
    ll cnt = 0;
    for(ll i = 1; i <= n; i++){
        cnt += max(0ll, m - t / i);
    }
    return cnt < k;
}

int main(){
    scanf("%I64d%I64d%I64d", &n, &m, &k); k = n * m + 1 - k;
    ll l = 0, r = n * m, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(!can(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%I64d", l);
}