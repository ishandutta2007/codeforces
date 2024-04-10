#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n, c[3], t[3];
    long long x, y, z;
    queue<long long> q[3];
    REP(i, 3) cin >> c[i];
    REP(i, 3) cin >> t[i];
    cin >> n;

    REP(i, 3) REP(j, min(c[i], n)) q[i].push(0);

    z = 0;
    REP(i, n) {
        cin >> x;
        y = x;
        REP(j, 3) {
            y = max(y, q[j].front()) + t[j];
            q[j].pop();
            q[j].push(y);
        }
        z = max(z, y - x);
    }

    cout << z << endl;
    return 0;
}