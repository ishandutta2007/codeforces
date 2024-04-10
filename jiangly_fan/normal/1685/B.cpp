#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int a, b, c, d;
        string s;
        cin >> a >> b >> c >> d >> s;
        if (ranges::count(s, 'A') != a + c + d) {
            cout << "NO\n";
            continue;
        }
        vector<int> vA, vB;
        int A = 0, B = 0, C = 0;
        for (int i = 0, j = 0; i < s.size(); i = j) {
            while (j < s.size() and (i == j or s[j] != s[j - 1]))
                j += 1;
            if ((j - i) & 1) C += (j - i) / 2;
            else if (s[i] == 'A') {
                vA.push_back((j - i) / 2);
                A += (j - i) / 2;
            }
            else {
                vB.push_back((j - i) / 2);
                B += (j - i) / 2;
            }
        }
        ranges::sort(vA);
        ranges::sort(vB);
        while (min(A, c) + min(B, d) + C < c + d) {
            if (A > c) {
                A -= vA.back();
                C += vA.back() - 1;
                vA.pop_back();
            }
            else if (B > d) {
                B -= vB.back();
                C += vB.back() - 1;
                vB.pop_back();
            }
            else break;
        }
        cout << (min(A, c) + min(B, d) + C >= c + d ? "YES\n" : "NO\n");
    }
    return 0;
}