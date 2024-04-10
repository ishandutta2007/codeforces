#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, H, M;
    cin >> N >> H >> M;
    vector<int> house(N, H);
    for (int i = 0; i < M; ++i) {
        int L, R, B;
        cin >> L >> R >> B;
        for (int i = L - 1; i < R; ++i) {
            house[i] = min(house[i], B);
        }
    }
    int ans = 0;
    for (auto& x : house) {
        ans += x * x;
    }
    cout << ans;
    return 0;
}