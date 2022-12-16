#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a[n];
    unordered_set<int> bads;
    unordered_map<int, int> memo;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        bads.insert(x);
    }

    int gcds[n];
    gcds[0] = a[0];
    for (int i = 1; i < n; i++) {
        gcds[i] = __gcd(gcds[i-1], a[i]);
    }

    ll amt = 1;

    for (int i = n-1; i >= 0; i--) {
        gcds[i] /= amt;
        int bl = gcds[i];
        if (bl == 1) {
            a[i] /= amt;
            continue;
        }
            

        int score = 0;
        if (memo.find(bl) != memo.end()) score = memo[bl];
        else {
            int og = score;
            int og2 = bl;
        for (int fac = 2; fac < sqrt(bl)+3; fac++) {
            while (bl % fac == 0) {
                bl /= fac;
                if (bads.find(fac) == bads.end()) score++;
                else score--;
            }
        }
        if (bl!= 1) {
            if (bads.find(bl) == bads.end()) score++;
            else score--;
        }
        memo[og2] = score-og;
        }

        if (score < 0) {
            amt *= gcds[i];
        }

        a[i] /= amt;
    }

    ll out = 0;
    for (int i = 0; i < n; i++) {
        if (memo.find(a[i]) != memo.end()) out += memo[a[i]];
        else {
            int og = out;
            int og2 = a[i];
        for (int fac = 2; fac < sqrt(a[i])+3; fac++) {
            while (a[i] % fac == 0) {
                a[i] /= fac;
                if (bads.find(fac) == bads.end()) out++;
                else out--;
            }
        }

        if (a[i] != 1) {
            if (bads.find(a[i]) == bads.end()) out++;
            else out--;
        }
        memo[og2] = out-og;
        }
    }
    cout << out << endl;
}