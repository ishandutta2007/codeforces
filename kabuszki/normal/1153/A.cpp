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
    int n, t;
    cin >> n >> t;
    VII v;
    REP(i, n) {
        int s, d;
        cin >> s >> d;
        if (s > t) v.EB(s, i);
        else {
            int k = t % d;
            int l = s % d;
            if (l < k) l += d;
            v.EB(t + l - k, i);
        }
    }
    sort(ALL(v));
    cout << v[0].ND + 1 << "\n";
}

#undef int

int main() {

    #define int long long
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}