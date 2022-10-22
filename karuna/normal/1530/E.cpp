#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int N = 30;
string S; int Count[N];

void solve() {
    cin >> S;
    for (int i = 0; i < N; i++) Count[i] = 0;
    for (int i = 0; i < S.size(); i++) {
        Count[S[i] - 'a'] += 1;
    }
    int first = 0, x = -1, d = 0;
    for (int i = 0; i < N; i++) {
        if (Count[i]) {
            first = i; break;
        }
    }
    if (Count[first] == S.size()) {
        cout << S << '\n'; return;
    }
    for (int i = 0; i < N; i++) {
        if (Count[i] == 1 && x == -1) {
            x = i;
        }
        if (Count[i]) d += 1;
    }
    string Ans = "";
    if (x != -1) {
        Ans += (char)('a' + x); Count[x] -= 1;
        for (int i = 0; i < N; i++) {
            while (Count[i]--) Ans += (char)('a' + i);
        }
        cout << Ans << '\n'; return;
    }

    Ans += (char)('a' + first); Count[first] -= 1;
    for (int i = first + 1; i < N; i++) {
        while (Count[i]--) Ans += (char)('a' + i);
    }
    if (Ans.size() >= Count[first]) {
        for (int i = 0; i < Ans.size(); i++) {
            cout << Ans[i];
            if (Count[first]) {
                cout << (char)('a' + first);
                Count[first] -= 1;
            }
        }
    }
    else {
        if (d == 2) {
            cout << Ans;
            while (Count[first]--) cout << (char)('a' + first);
        }
        else {
            cout << Ans[0] << Ans[1];
            int p = 1;
            while (p < Ans.size() && Ans[p] == Ans[1]) p += 1;
            while (Count[first]--) cout << (char)('a' + first);
            cout << Ans[p];
            for (int i = 2; i < p; i++) cout << Ans[i];
            cout << Ans.substr(p + 1);
        }
    }
    cout << '\n';
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}