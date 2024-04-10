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
        string inp;
        cin >> inp;
        char mode = inp[0];
        bool unq = true;
        int n = inp.size();
        for (int i = 1; i < n; i++) {
            if (inp[i] != mode) unq = false;
        }

        if (unq) cout << inp << endl;
        else {
            for (int i = 0; i < n; i++) {
                cout << "01";
            }
            cout << endl;
        }
    }
}