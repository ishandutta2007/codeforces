#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s, t;
    cin >> s >> t;

    int MOD = 1e9 + 7;

    string S = t + '#' + s;
    vector<int> prefix;
    int border = 0;
    prefix.push_back(border);
    for (int i = 1; i < S.size(); i++) {
        while (border > 0 && S[i] != S[border]) {
            border = prefix[border - 1];
        }

        if (S[i] == S[border]) {
            border++;
        }
        prefix.push_back(border);
    }

    vector<long long> a(s.size() + 1, 0LL);
    vector<long long> q1(s.size() + 1, 0LL);
    vector<long long> q2(s.size() + 1, 0LL);

    for (int i = 0; i < s.size(); i++) {
        if (prefix[i + t.size() + 1] == t.size()) {
            a[i+1] = (q2[i + 1 - t.size()] + i - t.size() + 2) % MOD;
        } else {
            a[i+1] = a[i];
        }
        q1[i+1] = (q1[i] + a[i+1]) % MOD;
        q2[i+1] = (q2[i] + q1[i+1]) % MOD;
    }

    cout << q1.back() << endl;



    return 0;
}