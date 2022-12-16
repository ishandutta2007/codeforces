#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        ll out = 0;
        ll i = 2;
        bool flag = false;
        while (x/(i+1) >= sqrt(x) || i <= 25*sqrt(x)) {
            if (i > y) {
                flag = true;
                break;
            }
            out += max((ll)0, min(x/(i+1), i-1));
            i++;
            
        }
        if (flag) {
            cout << out << endl;
            continue;
        }
        
        //cout << "i=" << i << endl;
        //cout << "out=" << out << endl;
        // want to handle the i's up until y
        ll res = x/(i+1);
        while (res > 0) {
            ll nextthreshold = 0;
            if (res != 1) nextthreshold = x/(res);
            else nextthreshold = x;
            if (nextthreshold > y) nextthreshold = y+1;
            //cout << " res = " << res << " next threshold= " << nextthreshold << endl;
            out += max((ll)0, res*(nextthreshold-i));
            i = nextthreshold;
            res = x/(i+1);
            if (i >= y) break;
        }
        cout << out << endl;
    }
}