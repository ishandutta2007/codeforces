#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)1e9 + 7;
const LL NS = (LL)5e5 + 4;
LL N, k;
LL a[NS];
priority_queue<LL> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> k;
    for(LL i = 1; i <= N; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + N + 1);
    reverse(a + 1, a + N + 1);
    LL SUM = 0, ans = 0, pos = -1;
    for(LL i = 1; i <= N; ++i){
        if(SUM < 0){
            pos = i - 1;
            a[i - 1] = SUM;
            break;
        }
        ans += SUM;
        SUM += a[i];
    }
    if(pos == -1){
        cout << ans;
        return 0;
    }
    for(LL i = 1; i <= N - pos + 1; ++i){
        a[i] = a[i + pos - 1];
    }
    N = N - pos + 1;
    for(LL i = 1; i <= k + 1; ++i){
        pq.push(0);
    }
    for(LL i = 1; i <= N - k - 1; ++i){
        LL val = pq.top(); pq.pop();
        ans += val + a[i];
        pq.push(val + a[i]);
    }
    cout << ans;
    return 0;
}