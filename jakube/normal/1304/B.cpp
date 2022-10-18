#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    map<string, int> cnts;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cnts[s]++;
    }

    string prefix;
    string middle;
    for (auto [s, c] : cnts) {
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t) {
            int mi = cnts[s];
            for (int i = 1; i < mi; i+=2) {
                prefix += s;
            }
            if (mi % 2)
                middle = s;
        } else {
            int mi = min(cnts[s], cnts[t]);
            for (int i = 0; i < mi; i++) {
                prefix += s;
            }
            cnts[s] -= mi;
            cnts[t] -= mi;
        }
    }

    cout << prefix.size() * 2 + middle.size() << endl;
    cout << prefix << middle;
    reverse(prefix.begin(), prefix.end());
    cout << prefix << endl;
}