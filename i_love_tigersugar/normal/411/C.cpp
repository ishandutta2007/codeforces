#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define greater qh9e38q2
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
ii a[4];
const string win="Team 1";
const string lose="Team 2";
const string draw="Draw";
bool greater(ii a,ii b,ii c,ii d) {
    return (a.fi>d.se && b.se>c.fi);
}
int main(void) {
    REP(i,4) cin >> a[i].fi >> a[i].se;
    if (greater(a[0],a[1],a[2],a[3]) && greater(a[0],a[1],a[3],a[2])) {
        cout << win;
        return 0;
    }
    swap(a[0],a[1]);
    if (greater(a[0],a[1],a[2],a[3]) && greater(a[0],a[1],a[3],a[2])) {
        cout << win;
        return 0;
    }
    if (!greater(a[2],a[3],a[0],a[1]) && !greater(a[3],a[2],a[0],a[1])) {
        cout << draw;
        return 0;
    }
    swap(a[0],a[1]);
    if (!greater(a[2],a[3],a[0],a[1]) && !greater(a[3],a[2],a[0],a[1])) {
        cout << draw;
        return 0;
    }
    cout << lose;
    return 0;
}