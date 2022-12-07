#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;


void jebaj() {

    int n;
    cin >> n;
    VII v(n), a(n);
    REP(i, n) {
        cin >> v[i].ST >> v[i].ND;
    }
    REP(i, n) cin >> a[i].ST >> a[i].ND;
    sort(ALL(v));
    sort(ALL(a));
    cout << v.front().ST + a.back().ST << " " << v.front().ND + a.back().ND << "\n";

}
int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}