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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        bool pos = false;
        bool npos = false;
        bool eh = true;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            if (npos && x != i+1 && a[i-1] == i) eh = false;
            if (x == i+1) pos = true;
            if (x != i+1) npos = true;
            
        }

        if (!npos) cout << 0 << endl;
        else if ((!pos) || eh) cout << 1 << endl;
        else cout << 2 << endl;
    }
}