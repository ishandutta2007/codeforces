#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    
    int res = 0;
    char last = '*';
    for (char c : s) {
        if (c == '*') {
            last = c;
        } else {
            if (a && (a >= b || last == 1) && last != 0) {
                a--;
                last = 0;
                res++;
            } else if (b && (b >= a || last == 0) && last != 1) {
                b--;
                last = 1;
                res++;
            } else {
                last = '*';
            }
        }
    }
    cout << res << endl;
}