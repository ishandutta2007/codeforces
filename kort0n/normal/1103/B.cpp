#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    string in;
    while(true) {
        cin >> in;
        if(in == "end" ) return 0;
        if(in == "mistake") return 0;
        cout << "? 0 1" << endl;
        cin >> in;
        if(in == "x") {
            cout << "! 1" << endl;
            continue;
        }
        int ng = 1;
        int ok = 1e9;
        while(ok - ng > 1) {
            int now = (ok + ng) / 2;
            if(now > 2 * ng) {
                now = 2 * ng;
            }
            //int now = 2 * ng;
            /*
            if(now * 2 >= ok) {
                now = (ng + ok) / 2;
            }
            */
            cout << "? " << ng << " " << now << endl;
            cin >> in;
            if(in == "e") return 0;
            if(in == "x") {
                ok = now;
            } else {
                ng = now;
            }
        }
        cout << "! " << ok << " " << endl;
        continue;
    }
    return 0;
}