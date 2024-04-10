#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i += 1)
        v.push_back(i);
    auto answer = [&](int u) {
        cout << "! " << u << endl;
        string s;
        cin >> s;
        if (s == ":)") exit(0);
    };
    auto query = [&](vector<int> v) {
        cout << "? " << v.size();
        for (int vi : v) cout << " " << vi;
        cout << endl;
        string s;
        cin >> s;
        return s == "YES";
    };
    auto merge = [&](vector<int>& x, vector<int>& y) {
        for (int yi : y) x.push_back(yi);
    };
    function<void(vector<int>)> find = [&](vector<int> v) {
        if (v.size() <= 2) {
            answer(v[0]);
            answer(v[1]);
        }
        vector<vector<int>> w(3);
        for (int i = 0; i < v.size(); i += 1)
            w[i % 3].push_back(v[i]);
        int q0 = query(w[0]);
        vector<int> nxt;
        if (q0) {
            int q1 = query(w[1]);
            if (q1) {
                merge(nxt, w[0]);
                merge(nxt, w[1]);
            }
            else {
                merge(nxt, w[0]);
                merge(nxt, w[2]);
            }
        }
        else {
            int q00 = query(w[0]);
            if (not q00) {
                merge(nxt, w[1]);
                merge(nxt, w[2]);
            }
            else {
                int q1 = query(w[1]);
                if (q1) {
                    merge(nxt, w[0]);
                    merge(nxt, w[1]);
                }
                else {
                    merge(nxt, w[0]);
                    merge(nxt, w[2]);
                }
            }
        }
        find(nxt);
    };
    find(v);
}