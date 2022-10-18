#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;

    int f = 0;
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'G' || s[i] == 'T') {
            if (f == 0) {
                f += 1;
                idx = i;
            }
            else if (f == 1 && (i - idx) % k == 0){
                cout << "YES" << endl;
                return 0;
            }
        }
        if (f == 1 && (s[i] == '#' && (i - idx) % k == 0)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}