#include <bits/stdc++.h>
using namespace std;

const string vowels = "aeiou";

int cnt(string const& s) {
    int cnt = 0;
    for (char c : s) {
        if (vowels.find(c) != string::npos)
            cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> v(n);
    for (auto& x : v)
        cin >> x;
    
    map<int, vector<string>> m;
    for (auto x : v)
        m[cnt(x)].push_back(x);

    vector<pair<string, string>> good;
    vector<pair<string, string>> bad;

    for (auto [c, ss] : m) {
        vector<vector<string>> by_last(5);
        for (auto s : ss) {
            int last;
            for (char c : s) {
                int pos = vowels.find(c);
                if (pos != string::npos)
                    last = pos;
            }
            by_last[last].push_back(s);
        }
        string rem;
        for (auto vv : by_last) {
            if (vv.size() % 2) {
                if (rem.empty())
                    rem = vv.back();
                else {
                    bad.push_back({rem, vv.back()});
                    rem.clear();
                }
                vv.pop_back();
            }
            for (int i = 0; i < vv.size(); i+=2) {
                good.push_back({vv[i], vv[i+1]});
            }
        }
    }

    int res = min(good.size(), (good.size() + bad.size()) / 2);
    cout << res << '\n';
    for (int i = 0; i < res; i++) {
        pair<string, string> first, second;
        if (!bad.empty()) {
            first = bad.back();
            bad.pop_back();
        } else {
            first = good.back();
            good.pop_back();
        }
        second = good.back();
        good.pop_back();
        cout << first.first << " " << second.first << "\n";
        cout << first.second << " " << second.second << "\n";
    }
}