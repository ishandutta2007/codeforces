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
    int n;
    cin >> n;
    VI v(n);
    REP(i, n) cin >> v[i];
    auto s = set<int>(ALL(v));

    int mi = *(s.begin());
    int cnt = 0;
    for (int a : v) cnt += (a == mi);
    if (cnt * 2 > n) cout << "Bob\n";
    else cout << "Alice\n";
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