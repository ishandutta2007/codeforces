#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 == 1 || s.front() == ')' || s.back() == '(') {
        cout << ":(" << endl;
        return 0;
    }
    s.front() = '(';
    s.back() = ')';
    int cl = n / 2 - 1, cr = n / 2 - 1;
    for (int i = 1; i < n - 1; ++i) {
        if (s[i] == '(')
            --cl;
        else if (s[i] == ')')
            --cr;
    }
    if (cl < 0 || cr < 0) {
        cout << ":(" << endl;
        return 0;
    }
    int sum = 0;
    for (int i = 1, j = 0; i < n - 1; ++i) {
        if (s[i] == '?') {
            if (j < cl)
                s[i] = '(';
            else
                s[i] = ')';
            ++j;
        }
        if (s[i] == '(') {
            ++sum;
        } else {
            if (sum == 0) {
                cout << ":(" << endl;
                return 0;
            }
            --sum;
        }
    }
    cout << s << endl;
    return 0;
}