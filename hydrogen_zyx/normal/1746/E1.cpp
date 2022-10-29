#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;


void out(vector<int> v) {
    cout << "? ";
    cout << v.size();
    for (auto x: v) cout << " " << x;
    cout << endl;
}

vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> v;
    for (auto x: a) v.push_back(x);
    for (auto x: b) v.push_back(x);
    return v;
}

void solve(vector<int> v) {
    if (v.size() == 1) {
        cout << "! " << v[0] << endl;
        return;
    } else if (v.size() == 2) {
        cout << "! " << v[0] << endl;
        string s;
        cin >> s;
        if (s == ":(") cout << "! " << v[1] << endl;
        return;
    }
    vector<int> tmp[3];
    for (int i = 0; i < v.size(); i++) {
        tmp[i % 3].push_back(v[i]);
    }
    out(tmp[0]);
    string s;
    cin >> s;
    if (s == "YES") {
        out(tmp[1]);
        cin >> s;
        if (s == "YES") {
            solve(merge(tmp[0], tmp[1]));
        } else {
            solve(merge(tmp[0], tmp[2]));
        }
    } else {
        out(tmp[0]);
        cin >> s;
        if (s == "YES") {
            out(tmp[1]);
            cin >> s;
            if (s == "YES") {
                solve(merge(tmp[0], tmp[1]));
            } else {
                solve(merge(tmp[0], tmp[2]));
            }
        } else {
            solve(merge(tmp[1], tmp[2]));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(i);
    solve(v);
}