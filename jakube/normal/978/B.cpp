#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int cur = 0;
    int res = 0;
    for (char c : s) {
        if (c == 'x') {
            cur++;
        } else {
            cur = 0;
        }
        if (cur == 3) {
            res++;
            cur--;
        }
    }
    cout << res << '\n';
    
}