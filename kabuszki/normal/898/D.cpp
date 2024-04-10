#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;



void jebaj() {
    int n, m, k;
    cin >> n >> m >> k;
    VI v(n), w(n);
    REP(i, n) {
        cin >> v[i];
    }
    sort(ALL(v));
    int pocz = 0, kon = 0;
    while (kon + 1 < v.size() && v[kon + 1] - v[pocz] < m) kon++;
    int res = 0;
    int toc = 0;
    while(pocz < v.size()) {
        int clocks = kon - pocz + 1 - toc;
        if (clocks >= k) {
            FORD(i, kon, kon - (clocks - k)) {
                w[i] = -1;
                res++;
                toc++;
            }
        }
        if (w[pocz] == -1) {
            toc--;
        }
        pocz++;
        while (kon + 1 < v.size() && v[kon + 1] - v[pocz] < m) kon++;
    }
    cout << res << "\n";
}
#undef int
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}