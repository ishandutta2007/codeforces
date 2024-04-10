#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, t;
    cin >> n >> t;
    
    string s;
    cin >> s;

    for (int i = 0; i < t; ++i) {
        string ss = "";
        for (int j = 0; j < n; ++j) {
            if (j < n-1 && s[j] == 'B' && s[j+1] == 'G') {
                ss += "GB";
                ++j;
            }
            else
                ss += s[j];
        }
        s = ss;
    }
    cout << s << endl;

    return 0;
}