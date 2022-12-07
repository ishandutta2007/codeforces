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


VI merger(vector<VI> v) {

    VI r;
    for (auto& a : v) for (int b : a) r.PB(b);
    return r;
}

void jebaj() {

    VI v = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    VI leap = v, nleap = v;
    leap[1] = 28;
    nleap[1] = 29;

    vector<VI> czeks = {merger({leap, leap, leap}),
    merger({nleap, leap, leap}),
    merger({leap, nleap, leap}),
    merger({leap, leap, nleap})};

    int n;
    cin >> n;
    VI in(n);
    REP(i, n) cin >> in[i];

    for (auto& cz : czeks) {

        REP(i, 12) {
            int a = 0;
            REP(j, n) a += (in[j] == cz[i + j]);
            if (a == n) {
            cout << "YES\n";
            return;
        }
        }

    }
    cout << "NO\n";
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