#include<bits/stdc++.h>
using namespace std;

#define int long long

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



void jebaj() {
    int n;
    cin >> n;
    VI v(n);
    REP(i, n) {
        cin >> v[i];
    }
    unordered_map<int, int> map_even, map_odd;
    map_odd[0] = 1;
    int ksor = 0, res = 0;
    for (int i = 0; i < n; i++) {
        ksor ^= v[i];
        if (i & 1) res += map_odd[ksor];
        else res += map_even[ksor];

        if (!(i & 1)) map_even[ksor]++;
        else map_odd[ksor] ++;
    }
    cout << res << "\n";
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