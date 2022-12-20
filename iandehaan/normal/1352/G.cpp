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
        int strt = 0;
        while (strt + 8 <= n) {
            //cout << "iter" << endl;
            cout << strt+2 << ' ' << strt+4 << ' ' << strt+1 << ' ' << strt+3 << ' ';
            strt += 4;
        }

        if (n-strt == 2) {
            cout << -1 << endl;
            continue;
        }
        if (n-strt == 3) {
            cout << -1 << endl;
            continue;
        }
        if (n-strt == 4) {
            cout << strt+2 << ' ' << strt+4 << ' ' << strt+1 << ' ' << strt+3 << endl;
            continue;
        }
        if (n-strt == 5) {
            //cout << "here " << strt << endl;
            cout << strt+2 << ' ' << strt+5 << ' ' << strt+3 << ' ' << strt+1 << ' ' << strt+4 << endl;
            continue;
        }
        if (n-strt == 6) {
            cout << strt+1 << ' ' << strt+5 << ' ' << strt+3 << ' ' << strt+6 << ' ' << strt+4 << ' ' << strt+2 << endl;
            continue;
        }
        if (n-strt == 7) {
            cout << strt+1 << ' ' << strt+4 << ' ' << strt+7 << ' ' << strt+5 << ' ' << strt+2 << ' ' << strt+6 << ' ' << strt+3 << endl; 
            continue;
        }



        cout << endl;
    }
}