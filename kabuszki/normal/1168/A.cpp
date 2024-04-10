#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;

bool spoko(const VI& v, int n, int m, int ile) {
    int last = m - 1;
    FORD(i, n - 1, 0) {
        if (last < v[i]) {
            if (v[i] + ile < m) return false;
            int a = (v[i] + ile) % m;
            if (a > last) a = last;
            last = a;
        } else {
            last = min(last, v[i] + ile);
        }
    }
    return true;
}

void jebaj() {
    int n, m;
    cin >> n >> m;
    VI v(n);
    REP(i, n) cin >> v[i];
    bool dupa = false;
    REP(i, n - 1) if (v[i] > v[i + 1]) {
        dupa = true;
        break;
    }
    if (!dupa) {
        cout << "0\n";
        return;
    }

    int pocz = 0, kon = m - 1;
    while (pocz + 1< kon) {
        int mid = (pocz + kon) / 2;
        if (spoko(v, n, m, mid)) kon = mid;
        else pocz = mid;
    }
    cout << kon << "\n";
}

#undef int

int main() {

    #define int long long
    int t = 1;
    //cin >> t;
    while (t--) {
        jebaj();
    }
    return 0;
}