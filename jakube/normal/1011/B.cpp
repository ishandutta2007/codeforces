#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), cnt(101, 0);
    for (auto& x : a) {
        cin >> x;
        cnt[x]++;
    }

    int L = 0; // possible
    int R = m + 1; // not possible
    while (L + 1 < R) {
        int M = (L + R) / 2;
        int part = 0;
        for (int c : cnt)
            part += c / M;
        if (part >= n)
            L = M;
        else
            R = M;
    }
    cout << L << '\n';
}