#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N);
        vector<int> cnt1(N);
        vector<int> cnt0(N);
        ll inv = 0;
        for (int i = 0; i < N; ++i){
            cin >> a[i];
            if (i) cnt1[i] = cnt1[i-1];
            if (a[i] == 1) cnt1[i]++;
            if (a[i] == 0) inv += cnt1[i];
        }
        for (int i = N-1; i >= 0; --i){
            if (i != N-1) cnt0[i] = cnt0[i+1];
            if (a[i] == 0) cnt0[i]++;
        }
        ll best = inv;
        for (int i = 0; i < N; ++i){
            ll cur = inv;
            if (a[i] == 0){
                cur += cnt0[i]-1;
                cur -= cnt1[i];
            }
            if (a[i] == 1){
                cur -= cnt0[i];
                cur += cnt1[i]-1;
            }
            best = max(best, cur);
        }
        cout << best << '\n';
    }
}