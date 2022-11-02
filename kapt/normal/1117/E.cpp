#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4;

main() {
    string s;
    cin >> s;
    int n = s.size();
    string s1, s2, s3;
    map<int, string> m;
    for (int i = 0; i < n; ++i) {
        string sn = "";
        s1.push_back('a' + i / 400);
        s2.push_back('a' + (i / 20) % 20);
        s3.push_back('a' + i % 20);
        sn.push_back('a' + i / 400);
        sn.push_back('a' + (i / 20) % 20);
        sn.push_back('a' + i % 20);
        m[i] = sn;
    }
    cout << "? " << s1 << endl;
    string a1, a2, a3;
    cin >> a1;
    cout << "? " << s2 << endl;
    cin >> a2;
    cout << "? " << s3 << endl;
    cin >> a3;
    map<string, int> m2;
    for (int i = 0; i < n; ++i) {
        string sn = "";
        sn.push_back(a1[i]);
        sn.push_back(a2[i]);
        sn.push_back(a3[i]);
        m2[sn] = i;
    }
    string ans = "";
    for (int i = 0; i < n; ++i) {
        int j = i;
        j = m2[m[j]];
        ans.push_back(s[j]);
    }
    cout << "! " << ans;
    return 0;
}