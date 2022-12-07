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
    int n, m, k;
    cin >> n >> m >> k;
    VI v(n);
    REP(i, n) cin >> v[i];
    sort(ALL(v));
    reverse(ALL(v));
    int ile_drugie = m / (k + 1);
    cout << v[0] * (m - ile_drugie) + v[1] * ile_drugie << "\n";
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