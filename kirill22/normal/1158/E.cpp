#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> d;

string ask() {
    cout << "? ";
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    string res;
    cin >> res;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    d.resize(n);
    vector<int> h(n);
    vector<vector<int>> tmp;
    tmp.push_back({0});
    tmp.push_back({});
    for (int i = 1; i < n; i++) {
        tmp[1].push_back(i);
    }
    int j = 1;
    while (j * 2 < n) j *= 2;
    while (j) {
        vector<vector<int>> tmp2;
        fill(d.begin(), d.end(), 0);
        for (int i = 0; i < (int) tmp.size(); i += 4) {
            for (auto v : tmp[i]) {
                d[v] = j;
            }
        }
        auto A = ask();
        fill(d.begin(), d.end(), 0);
        for (int i = 0; i < (int) tmp.size(); i += 4) {
            for (auto v : tmp[i]) {
                d[v] = j - 1;
            }
        }
        auto B = ask();
        fill(d.begin(), d.end(), 0);
        for (int i = 2; i < (int) tmp.size(); i += 4) {
            for (auto v : tmp[i]) {
                d[v] = j;
            }
        }
        auto C = ask();
        fill(d.begin(), d.end(), 0);
        for (int i = 2; i < (int) tmp.size(); i += 4) {
            for (auto v : tmp[i]) {
                d[v] = j - 1;
            }
        }
        auto D = ask();
        for (int i = 0; i < (int) tmp.size(); i++) {
            if (i % 2 == 0) {
                tmp2.push_back(tmp[i]);
                continue;
            }
            if (i % 4 == 1) {
                tmp2.push_back({});
                for (auto v : tmp[i]) {
                    if (B[v] == '1') {
                        tmp2.back().push_back(v);
                    }
                }
                tmp2.push_back({});
                for (auto v : tmp[i]) {
                    if (B[v] == '0' && A[v] == '1') {
                        tmp2.back().push_back(v);
                        h[v] = h[tmp[i - 1][0]] + j;
                    }
                }
                tmp2.push_back({});
                for (auto v : tmp[i]) {
                    if (A[v] == '0') {
                        tmp2.back().push_back(v);
                    }
                }
            } else {
                tmp2.push_back({});
                for (auto v : tmp[i]) {
                    if (D[v] == '1') {
                        tmp2.back().push_back(v);
                    }
                }
                tmp2.push_back({});
                for (auto v : tmp[i]) {
                    if (D[v] == '0' && C[v] == '1') {
                        tmp2.back().push_back(v);
                        h[v] = h[tmp[i - 1][0]] + j;
                    }
                }
                tmp2.push_back({});
                for (auto v : tmp[i]) {
                    if (C[v] == '0') {
                        tmp2.back().push_back(v);
                    }
                }
            }
        }
        tmp = tmp2;
        j /= 2;
    }
    vector<pair<int, int>> ans;
    for (int j = 0; j < 3; j++) {
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            if (h[i] % 3 == j) {
                tmp.push_back(i);
            }
        }
        vector<string> res(10);
        for (int bit = 0; bit < 10; bit++) {
            fill(d.begin(), d.end(), 0);
            for (auto v : tmp) {
                if (v >> bit & 1) {
                    d[v] = 1;
                }
            }
            res[bit] = ask();
        }
        for (int i = 1; i < n; i++) {
            if ((h[i] + 2) % 3 == j) {
                int pr = 0;
                for (int bit = 0; bit < 10; bit++) {
                    if (res[bit][i] == '1') {
                        pr += (1 << bit);
                    }
                }
                ans.push_back({i, pr});
            }
        }
    }
    cout << "! " << endl;
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << endl;
    }
}