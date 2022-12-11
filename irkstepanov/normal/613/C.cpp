#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

string stupid(const vector<int>& v)
{
    string s = "";
    for (int i = 0; i < sz(v); ++i) {
        for (int j = 0; j < v[i]; ++j) {
            s += (char)(i + 'a');
        }
    }
    return s;
}

pair<string, bool> solve(const vector<int>& b)
{
    int n = sz(b);
    int odd = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] & 1) {
            ++odd;
        }
    }
    if (odd >= 2) {
        return mp("", false);
    }
    string s = "";
    for (int i = 0; i < n; ++i) {
        if (b[i] & 1) {
            continue;
        }
        for (int j = 0; j < b[i] / 2; ++j) {
            s += (char)(i + 'a');
        }
    }
    string t = s;
    reverse(all(t));
    for (int i = 0; i < n; ++i) {
        if (!(b[i] & 1)) {
            continue;
        }
        for (int j = 0; j < b[i]; ++j) {
            s += (char)(i + 'a');
        }
    }
    s += t;
    return mp(s, true);
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int n;
    cin >> n;
    int sum = 0;

    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cin >> cnt[i];
        sum += cnt[i];
    }

    for (int k = sum; k >= 2; --k) {///k nice cuts
        vector<int> b(n);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] % k) {
                ok = false;
                break;
            } else {
                b[i] = cnt[i] / k;
            }
        }
        if (!ok) {
            continue;
        }
        if (k % 2 == 0) {
            string t = stupid(b);
            string rt = t;
            reverse(all(rt));
            string s = "";
            for (int i = 0; i < k; ++i) {
                if (i & 1) {
                    s += rt;
                } else {
                    s += t;
                }
            }
            cout << k << "\n" << s << "\n";
            return 0;
        } else {
            pair<string, bool> p = solve(b);
            if (!p.second) {
                continue;
            }
            cout << k << "\n";
            for (int i = 0; i < k; ++i) {
                cout << p.first;
            }
            cout << "\n";
            return 0;
        }
    }

    pair<string, bool> p = solve(cnt);
    if (p.second) {
        cout << "1\n" << p.first << "\n";
        return 0;
    }

    cout << "0\n";
    cout << stupid(cnt) << "\n";

}