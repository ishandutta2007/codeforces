#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s) 
        cnt += c == 'a';
    int other = s.size() - cnt;
    cout << cnt + min(cnt-1, other) << '\n';
}