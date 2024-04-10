#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        int l = 0;
        int i = 0;
        while (i < n && s[i] == '<') {
            l++;
            i++;
        }
        int r = 0;
        i = n-1;
        while (i >= 0 && s[i] == '>') {
            r++;
            i--;
        }
        cout << min(l, r) << '\n';
    }
}