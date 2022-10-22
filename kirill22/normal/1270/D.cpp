#include<bits/stdc++.h>

using namespace std;

pair<int, int> ask(vector<int> a) {
    cout << "? ";
    for (auto i : a) {
        cout << i + 1 << " ";
    }
    cout << endl;
    int pos, x;
    cin >> pos >> x;
    return {pos - 1, x};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    iota(a.begin(), a.end(), 0);
    auto res = ask(a);
    vector<int> id;
    for (int i = 0; i < k; i++) {
        if (i != res.first) {
            a[i] = k;
            if (ask(a).first == res.first) {
                id.push_back(i);
            }
            a[i] = i;
        }
    }
    a[res.first] = k;
    auto res2 = ask(a);
    //cout << res.second << " " << res2.second << " " << (int) id.size() << endl;
    if (res2.second < res.second) {
        cout << "! " << (int) id.size() + 1 << endl;
    } else {
        cout << "! " << k - (int) id.size() << endl;
    }
}