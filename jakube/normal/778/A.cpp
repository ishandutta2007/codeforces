#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string t, p;
    cin >> t >> p;
    vector<int> a(t.size());
    for (int i = 0; i < t.size(); i++) {
        cin >> a[i];
    }

    int L = 0; 
    int R = t.size();
    while (L + 1 < R) {
        int M = (L + R) / 2;

        vector<bool> b(t.size(), true);
        for (int i = 0; i < M; i++)
            b[a[i]-1] = false;

        int idx = 0;
        for (int i = 0; i < t.size(); i++) {
            if (!b[i]) continue;

            if (idx < p.size() && p[idx] == t[i]) 
                idx++;
        }

        if (idx == p.size())
            L = M;
        else 
            R = M;
    }

    cout << L << endl;
}