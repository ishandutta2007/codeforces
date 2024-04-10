#include <bits/stdc++.h>

using namespace std;

const int M = 100100;

string s, t;
int n;
int d[M];
int lcp = 0;
set<string> ans;

void pre() {
    fill(d, d + M, 0);
    lcp = 0;

    t.push_back('$');
    for (int i = n - 1; i >= 0; --i)
        if (s[i] == t[i + 1])
            d[i] = 1 + d[i + 1];
        else
            d[i] = 0;


    while (lcp < n && s[n - 1 - lcp] == t[n - 1 - lcp])
        ++lcp;
}

void kill() {
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i])
            continue;

        if (d[i] + lcp >= n - i - 1) {
            string temp = s.substr(0, i) + string(1, t[i]) + s.substr(i, n - i);
            ans.insert(temp);
            //cerr << temp << "!\n";
        }

        if (s[i] != t[i])
            break;
    }


}

int main() {
    cin >> n;
    cin >> s >> t;
    pre();
    kill();
    swap(s, t);
    pre();
    kill();
    cout << ans.size() << "\n";
    return 0;
}