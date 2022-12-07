#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
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



void jebaj() {
    int n, k;
    cin >> n >> k;
    VI v(k);
    vector<VI> pos(n);
    REP(i, k) {
        int a;
        cin >> a;
        a--;
        v[i] = a;
        pos[a].PB(i);
    }
    int res = 0;
    FOR(i, 0, n - 1) {
        if (pos[i].empty()) {
            res++;
        }
        for (int a : {-1, 1}) if (a + i >= 0 && a + i < n) {
            if (pos[i].empty()) {
                res++;
                continue;
            }
            int fi = pos[i].front();
            if (pos[a + i].empty()) {
                res++;
                continue;
            }
            int la = pos[a + i].back();
            res += (la < fi);
        }
    }
    cout << res << "\n";
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