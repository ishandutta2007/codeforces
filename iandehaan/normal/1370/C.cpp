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
        int ogn = n;
        if (n == 1) {
            cout << "FastestFinger" << endl;
            continue;
        }
        int numeven = 0;
        int numodd = 0;
        for (int i = 2; i <= sqrt(n)+3; i++) {
            while (n % i == 0) {
                n /= i;
                if (i % 2 == 0) numeven++;
                else numodd++;
            }
        }

        if (n != 1) {
            if (n % 2 == 1) numodd++;
            else numeven++;
        }

        //cout << numeven << ' ' << numodd << endl;
        if (ogn % 2 == 1) {
            // if it's not 1 but odd, just divide by itself
            cout << "Ashishgup" << endl;
        } else {
            if (numodd != 0) {
                if (numeven > 1) {
                    // divide by n/4,
                    // then FastestFinger deals with 4
                    // has to subtract 1
                    // we divide by 3
                    // we win
                    cout << "Ashishgup" << endl;
                } else {
                    
                    if (numodd == 1) cout << "FastestFinger" << endl;
                    else cout << "Ashishgup" << endl;
                }
            } else {
                if (ogn != 2) cout << "FastestFinger" << endl;
                else cout << "Ashishgup" << endl;
            }
        }
    }
}