#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    vb pos(26, true);

    bool det = false;
    int ans = 0;

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        char op;
        string str;
        cin >> op >> str;

        if (det) {
            if (op != '.') 
                ans++;
            continue;
        }

        if (op == '.') {
            for (char c : str) {
                pos[c - 'a'] = false;
            }
        } else if (op == '!') {
            vb has(26, false);
            for (char c : str) {
                has[c - 'a'] = true;
            }

            for (int j = 0; j < 26; j++)
                if (!has[j])
                    pos[j] = false;
        } else if (op == '?') {
            pos[str[0] - 'a'] = false;
        }

        int ct = 0;
        for (bool b : pos)
            ct += b;
        if (ct == 1)
            det = true;
    }

    cout << ans << endl;
    return 0;
}