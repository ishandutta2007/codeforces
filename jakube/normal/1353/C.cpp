#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 500'000;
    vector<long long> psum(MAX+1);
    for (int i = 1; i <= MAX; i++) {
        psum[i] = psum[i-1] + 8 * (long long)i * i;
    }

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int n;
        cin >> n;
        cout << psum[n/2] << '\n';
    }
}