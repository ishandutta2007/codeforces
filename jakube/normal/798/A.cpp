#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        cnt += s[i] != s[j];
    }

    if ((s.size() % 2 && cnt <= 1) || (s.size() % 2 == 0 && cnt == 1)) cout << "YES" << endl;
    else cout << "NO" << endl;
}