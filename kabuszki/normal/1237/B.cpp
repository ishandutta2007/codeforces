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

void jebaj() {
    int n;
    cin >> n;
    VI v(n), w(n);
    REP(i, n) cin >> v[i];
    REP(i, n) cin >> w[i];
    VI rev_w(n + 1);
    REP(i, n) rev_w[w[i]] = i;
    int max_position = -1, res = 0;
    REP(i, n) {
        int pos = rev_w[v[i]];
        if (pos < max_position) res++;
        max_position = max(max_position, pos);
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