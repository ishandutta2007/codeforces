#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

long long factorial(int n) {
    long long r = 1;
    for (int i = 2; i <= n; i++)
        r = (r * i) % MOD;
    return r;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> appearance(m+1);
    for (int i = 0; i < n; i++) {
        int g;
        cin >> g;

        for (int j = 0; j < g; j++) {
            int type;
            cin >> type;
            appearance[type].push_back(i);
        }
    }

    sort(appearance.begin(), appearance.end());
    long long r = 1;
    int cnt = 1;
    for (int i = 2; i < appearance.size(); i++) {
        if (appearance[i] == appearance[i-1])
            cnt++;
        else
        {
            r = (r * factorial(cnt)) % MOD;
            cnt = 1;
        }
    }

    cout << ((r * factorial(cnt)) % MOD) << endl;
    
    return 0;
}