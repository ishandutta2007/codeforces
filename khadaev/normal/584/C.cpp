#include <bits/stdc++.h>
using namespace std;
char other(char x, char y) {
    if (x != 'a' && y != 'a') return 'a';
    if (x != 'b' && y != 'b') return 'b';
    return 'c';
}

void fail() {
    cout << "-1\n";
    exit(0);
}

int main() {
    int n, t;
    string s1, s2;
    cin >> n >> t;
    if (n < t) fail();
    cin >> s1 >> s2;
    int match = 0;
    for (int i = 0; i < n; ++i)
        if (s1[i] == s2[i]) ++match;
    int diff = n - match;
    if ((diff + 1) / 2 > t) fail();
    int res = t - (diff / 2);
    //cout << diff << " " << match << "\n";
    if (res <= match + ((diff + 1) / 2)) {
        int resm = 0, resd = 0;
        resd += diff % 2;
        res -= diff % 2;
        if (res <= match) {
            resm = res;
        } else {
            resm = match;
            resd += 2 * (res - match);
        }
        int resl = (diff - resd) / 2;
        int resr = resl;
        //cout << resm << " " << resd << " " << resl << " " << resr << "\n";
        for (int i = 0; i < n; ++i) {
            if (s1[i] == s2[i]) {
                if (resm) {
                    --resm;
                    cout << other(s1[i], s2[i]);
                } else cout << s1[i];
            } else {
                if (resd) {
                    --resd;
                    cout << other(s1[i], s2[i]);
                } else if (resl) {
                    --resl;
                    cout << s1[i];
                } else cout << s2[i];
            }
        }
    } else fail();
};