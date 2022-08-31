#include <bits/stdc++.h>
using namespace std;
void no() {
    cout << 0 << endl;
    exit(0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<pair<char, int>> d;
    for (int i = 0, j; i < s.length(); i = j) {
        j = i;
        while (j < s.length() && s[i] == s[j])
            ++j;
        d.emplace_back(s[i], j - i);
    }
    if (d.size() % 2 == 0)
        no();
    int mid = d.size() / 2;
    if (d[mid].second < 2)
        no();
    for (int i = 0; i < mid; ++i)
        if (d[i].first != d[d.size() - i - 1].first || d[i].second + d[d.size() - i - 1].second < 3)
            no();
    cout << d[mid].second + 1 << endl;
    return 0;
}