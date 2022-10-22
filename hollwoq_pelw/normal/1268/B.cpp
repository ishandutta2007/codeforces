#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, cnt[2] = {0, 0};
    cin >> n;
    for (int i = 0; i < n; i++){
        int x = i & 1, a;
        cin >> a;
        cnt[x] += a / 2;
        cnt[x ^ 1] += (a + 1) / 2;
    }
    cout << min(cnt[0], cnt[1]);
}