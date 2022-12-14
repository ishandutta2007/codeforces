#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)1e9 + 7;
const LL NS = (LL)1e5 + 4;
LL T, N;
LL a[NS];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        for(LL i = 1; i <= N; ++i){
            cin >> a[i];
        }
        sort(a + 1, a + N + 1);
        LL ans = 0;
        for(LL i = 1; i <= N; ++i){
            ans += a[i];
        }
        LL gop = ans / (N - 1);
        gop = max(gop, a[N]);
        LL val = gop * (N - 1);
        if(val < ans){
            val += N - 1;
        }
        cout << val - ans << '\n';
    }
    return 0;
}