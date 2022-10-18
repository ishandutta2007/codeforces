#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    int n = s.size();
    vector<int> p(s.size(), 0);
    int border = 0;
    set<int> se;
    for (int i = 1; i < s.size(); i++) {
        while (border > 0 && s[i] != s[border]) {
            border = p[border-1];
        }
        border += s[i] == s[border];
        p[i] = border;
        if (i < n-1) se.insert(border);
    }

    int result = p.back();
    while (result > 0 && se.count(result) == 0) {
        result = p[result-1];
    }

    if (result > 0) {
        cout << s.substr(0, result) << endl;
    }
    else
        cout << "Just a legend" << endl;

    return 0;
}