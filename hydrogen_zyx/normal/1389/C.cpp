#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10][10];
bool b[10][10];
int c[10];
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        if (s.length() == 1) {
            cout << 0 << endl;
            continue;
        }
        bool f = 1;
        for (int i = 1; i < s.length(); i++)
            if (s[i] != s[0]) f = 0;
        if (f) {
            cout << 0 << endl;
            continue;
        }
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for (int i = 0; i < s.length(); i++) {
            int num = s[i] - '0';
            for (int j = 0; j < 10; j++) {
                bool b1 = 0, b2 = 0;
                if (b[num][j] == 0) b1 = 1;
                if (b[j][num] == 1) b2 = 1;
                if (b1) {
                    b[num][j] = 1;
                    a[num][j]++;
                }
                if (b2) {
                    b[j][num] = 0;
                    a[j][num]++;
                }
            }
        }
        int mmax = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                mmax = max(mmax, a[i][j] - b[i][j]);
            }
        }
        int mmmax = 0;
        for (int i = 0; i < s.length(); i++) {
            c[s[i] - '0']++;
            mmmax = max(mmmax, c[s[i] - '0']);
        }
        int aaans = min((int)s.length() - mmmax, (int)s.length() - mmax);
        cout << aaans << endl;
    }
}