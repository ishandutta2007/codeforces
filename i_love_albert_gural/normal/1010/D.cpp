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

void solve(vector<string> &ops, vvi &ch, vb &val, vvi &flip, int loc) {
    string s = ops[loc];
    if (s == "IN") {
        val[loc] = ch[loc][0];
        flip[loc].push_back(loc);
        return;
    }

    int l = ch[loc][0] - 1;
    solve(ops, ch, val, flip, l);

    if (s == "NOT") {
        val[loc] = !val[l];
        swap(flip[loc], flip[l]);
        return;
    }

    int r = ch[loc][1] - 1;
    solve(ops, ch, val, flip, r);

    if (flip[l].size() < flip[r].size())
        swap(l, r);

    if (s == "XOR") {
        val[loc] = val[l] ^ val[r];
        swap(flip[loc], flip[l]);
        flip[loc].insert(flip[loc].end(), all(flip[r]));
    } else if (s == "AND") {
        val[loc] = val[l] & val[r];
        if (((!val[l]) & val[r]) != val[loc])
            swap(flip[loc], flip[l]);
        if (((!val[r]) & val[l]) != val[loc])
            flip[loc].insert(flip[loc].end(), all(flip[r]));
    } else {
        val[loc] = val[l] | val[r];
        if (((!val[l]) | val[r]) != val[loc])
            swap(flip[loc], flip[l]);
        if (((!val[r]) | val[l]) != val[loc])
            flip[loc].insert(flip[loc].end(), all(flip[r]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vector<string> op(N);
    vvi ch(N);

    for (int i = 0; i < N; i++) {
        cin >> op[i];
        if (op[i] == "IN" || op[i] == "NOT") {
            int c;
            cin >> c;
            ch[i].push_back(c);
        } else {
            int c;
            cin >> c;
            ch[i].push_back(c);
            cin >> c;
            ch[i].push_back(c);
        }
    }

    vb val(N);
    vvi flip(N);
    solve(op, ch, val, flip, 0);

    set<int> flips;
    for (int v : flip[0])
        flips.insert(v);

    for (int i = 0; i < N; i++) {
        if (op[i] != "IN") continue;
        bool res = val[0];
        if (flips.count(i)) res = !res;
        if (res) cout << '1';
        else cout << '0';
    }
    cout << endl;

    return 0;
}