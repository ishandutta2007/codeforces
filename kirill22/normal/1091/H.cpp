// author`s solution

#pragma GCC optimize("Ofast", "O3")
#pragma GCC target("avx2", "popcnt")

#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 22;
bitset<N> dp[200], can;
vector<int> prime;
int G[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    can.set();
    can[0] = can[1] = 0;
    for (int i = 2; i < N; i++) {
        if (can[i]) {
            prime.push_back(i);
            for (int j = i + i; j < N; j += i) {
                can[j] = 0;
            }
        }
    }
    for (auto x : prime) {
        for (auto y : prime) {
            if (x * y >= N) {
                break;
            }
            can[x * y] = 1;
        }
    }
    
    int n, f;
    cin >> n >> f;
    can[f] = 0;
    for (int i = 0; i < N; i++) {
        while (dp[G[i]][i]) {
            G[i]++;
        }
        dp[G[i]] |= (can << i);
    }
    int g = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g ^= G[b - a - 1];
        g ^= G[c - b - 1];
    }
    cout << (g ? "Alice\nBob" : "Bob\nAlice");
}