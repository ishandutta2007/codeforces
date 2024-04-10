#include <bits/stdc++.h>
using namespace std;

int get(string s) {
    if (s.size() == 1) {
        return 0;
    }
    int n = s.size();
    int ind = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] > s[ind]) {
            ind = i;
        } else if (s[i] == s[ind]) {
            if (s[i] - s[i - 1] == 1) {
                ind = i;
                continue;
            }
            if (i != n - 1 && s[i] - s[i + 1] == 1) {
                ind = i;
            }
        }
    }
    int ans = 0;
    if (ind == 0) {
        if (s[ind] - s[ind + 1] == 1) {
            ans++;
        }
        string t;
        for (int i = ind + 1; i < n; ++i) {
            t.push_back(s[i]);
        }
        ans += get(t);
        return ans;
    }
    if (ind == n - 1) {
        if (s[ind] - s[ind - 1] == 1) {
            ans++;
        }
        string t;
        for (int i = 0; i < ind; ++i) {
            t.push_back(s[i]);
        }
        ans += get(t);
        return ans;
    }
    string t1;
    for (int i = 0; i < ind; ++i) {
        t1.push_back(s[i]);
    }
    string t2;
    for (int i = ind + 1; i < n; ++i) {
        t2.push_back(s[i]);
    }
    if (s[ind] - s[ind - 1] == 1 || s[ind] - s[ind + 1] == 1) {
        return 1 + get(t1 + t2);
    }
    return get(t1) + get(t2);
}

main() {
    int n; string s;
    cin >> n >> s;
    cout << get(s);
    return 0;
}