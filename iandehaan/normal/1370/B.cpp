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
        int a[2*n];
        for (int i = 0; i < 2*n; i++) cin >> a[i];

        int numodd = 0;
        int numselected = 0;
        for (int i = 0; i < 2*n; i++) {
            if (a[i] % 2 != 0) numodd++;
        }
        if (numodd % 2 == 0) numodd = min(numodd, 2);
        else numodd = 1;

        bool selected[2*n];
        for (int i = 0; i < 2*n; i++) selected[i] = false;

        for (int i = 0; i < 2*n; i++) {
            if (selected[i]) continue;
            if (numodd != 0 && a[i] % 2 != 0) {
                //cout << "odd strike on " << i+1 << endl;
                selected[i] = true;
                numselected++;
                numodd--;
                continue;
            }

            if (numselected < 2 && numodd == 0 && a[i] % 2 == 0) {
                //cout << "even strike on " << i+1 << endl;
                selected[i] = true;
                numselected++;
                continue;
            }

            for (int j = i+1; j < 2*n; j++) {
                if (selected[j]) continue;

                if (a[i] % 2 == 0 && a[j] % 2 == 0) {
                    selected[j] = true;
                    cout << i+1 << ' ' << j+1 << endl;
                    break;
                }

                if (a[i] % 2 != 0 && a[j] % 2 != 0) {
                    selected[j] = true;
                    cout << i+1 << ' ' << j+1 << endl;
                    break;
                }
            }
            //cout << "end on " << i+1 << endl;
        }
    }
}