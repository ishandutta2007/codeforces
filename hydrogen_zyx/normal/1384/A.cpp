#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int aa[300];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        s.clear();
        for (int i = 1; i <= n; i++) cin >> aa[i];
        for (int i = 0; i < 100; i++) s.push_back('a');
        cout << s << endl;
        for (int i = 1; i <= n; i++) {
            int a = aa[i];
            s[a] = s[a] + 1;
            if (s[a] > 'z') s[a] -= 26;
            cout << s << endl;
        }
    }
}