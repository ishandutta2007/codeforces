#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool used[n];
        bool blah[n];
        memset(used, false, sizeof used);
        memset(blah, false, sizeof blah);
        //cout << "blah" << endl;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            bool found = false;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                if (!found && (!used[x-1])) {
                    //cout << i << ' ' << x << endl;
                    used[x-1] = true;
                    found = true;
                    blah[i] = true;
                }
            }
        }

        int prince = -1;
        int princess = -1;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                prince = i+1;
            }
            if (!blah[i]) {
                princess = i+1;
            }
        }

        if (prince != -1 && princess != -1) {
            cout << "IMPROVE" << endl;
            cout << princess << ' ' << prince << endl;
        } else {
            cout << "OPTIMAL" << endl;
            //cout << princess << ' ' << prince << endl;
        }
    }
}