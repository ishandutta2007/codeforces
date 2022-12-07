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

int zapytaj(VI& v, VI& w) {
    if (v.empty() || w.empty()) return 0;
    cout << SIZE(v) << " " << SIZE(w) << " ";
    for (int a : v) cout << a << " ";
    for (int b : w) cout << b << " ";
    cout << endl;
    int a;
    cin >> a;
    return a;
}

void jebaj() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < 8; i++) {
        VI v, w;
        FOR(j, 1, n) {
            if (j & (1 << i)) v.PB(j);
            else w.PB(j);
        }
        res = max(res, zapytaj(v, w));
    }
    cout << -1 << " " << res << endl;
}

#undef int

int main() {

    #define int long long
    int t = 1;
    cin >> t;
    while (t--) {
        jebaj();
    }
    return 0;
}