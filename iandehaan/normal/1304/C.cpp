#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;

        int lastlow = m;
        int lasthigh = m;
        int lasttime = 0;
        
        bool good = true;
        for (int i = 0; i < n; i++) {
            int time, low, high;
            cin >> time >> low >> high;

            int timediff = time-lasttime;
            int besthigh = lasthigh+timediff;
            int bestlow = lastlow-timediff;
            //cout << lastlow << ' ' << lasthigh << endl;
            //cout << bestlow << ' ' << besthigh << endl;
            if (bestlow <= high && besthigh >= low) {
                lastlow = max(bestlow, low);
                lasthigh = min(besthigh, high);
            } else {
                good = false;
            }

            lasttime = time;

        }

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }
}