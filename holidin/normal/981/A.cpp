#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    bool flag = false, flag1 = false;
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size() - 1; ++i)
    if (s[i] != s[i + 1])
        flag = true;
    for (int i = 0; i < s.size() / 2; ++i)
    if (s[i] != s[s.size() - i - 1])
        flag1 = true;
    if (flag1) {
        cout << s.size();
        return 0;
    }
    if (flag) {
        cout << s.size() - 1;
    } else
        cout << 0;
}