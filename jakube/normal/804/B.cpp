#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    
    long long steps = 0;
    long long bs = 0;
    for (int idx = s.size() - 1; idx >= 0; idx--) {
        if (s[idx] == 'b')
            bs++;
        else {
            steps += bs;
            bs = (bs * 2) % MOD;
        }
    }

    cout << steps % MOD << endl;
}