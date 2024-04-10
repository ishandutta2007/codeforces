#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, d;
    cin >> X >> d;
    
    vector<long long> res;
    long long last = 1;
    
    while (X) {
        int cnt = 0;
        while ((1 << (cnt + 1)) - 1 <= X)
            cnt++;
        for (int i = 0; i < cnt; i++)
            res.push_back(last);
        last += d;

        X -= (1 << cnt) - 1;
    }

    cout << res.size() << endl;
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << endl;
}