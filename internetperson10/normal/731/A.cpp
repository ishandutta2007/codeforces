#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int sum = 0;
    char c = 'a';
    for(int i = 0; i < s.size(); i++) {
        sum += min((26 + s[i] - c) % 26, (26 + c - s[i]) % 26);
        c = s[i];
    }
    cout << sum << '\n';
}