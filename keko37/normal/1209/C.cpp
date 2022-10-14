#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int t, n;
string s;
int col[MAXN];

bool moze (int x) {
    for (int i=0; i<n; i++) col[i] = 0;
    int prosli = x;
    for (int i=n-1; i>=0; i--) {
        int val = s[i] - '0';
        if (val <= prosli) {
            col[i] = 1;
            prosli = val;
        }
    }

    prosli = x;
    for (int i=0; i<n; i++) {
        int val = s[i] - '0';
        if (col[i] == 1) continue;
        if (prosli <= val) {
            col[i] = 2;
            prosli = val;
        }
    }
    for (int i=0; i<n; i++) {
        if (col[i] == 0) return 0;
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        bool naso = 0;
        for (int i=0; i<10; i++) {
            if (moze(i)) {
                naso = 1;
                for (int i=0; i<n; i++) {
                    cout << col[i];
                }
                cout << '\n';
                break;
            }
        }
        if (!naso) cout << "-\n";
    }
    return 0;
}