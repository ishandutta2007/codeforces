#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    n += 2;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long left = abs(v[0] - v[1]) - 1;
    long long right = numeric_limits<int>::max();
    while (left + 1 < right) {
        auto m = (left + right) / 2;

        set<int> s;
        s.insert(v[0]);
        s.insert(v[1]);
        for (int i = 2; i < n; i++) {
            while (!s.empty() && abs(*s.begin() - v[i]) > m)
                s.erase(s.begin());
            while (!s.empty() && abs(*s.rbegin() - v[i]) > m)
                s.erase(*s.rbegin());
            if (s.empty())
                break;
            s.insert(v[i]);
        }

        if (s.empty())
            left = m;
        else
            right = m;
    }
    cout << right << endl;
}