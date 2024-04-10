#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int o = 0;
    for (char c : s) {
        if (c == 'o')
            o++;
    }


    int n = s.size();
    if (o == 0 || (n - o) % o == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}