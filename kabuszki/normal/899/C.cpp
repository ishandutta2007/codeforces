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

    int n;
    cin >> n;

    int x = (n * (n + 1)) / 4;
    VI v;
    FORD(i, n, 1) {
        if (i <= x) {
            v.PB(i);
            x -= i;
        }
    }
    if ((n * (n + 1)) % 4 == 0) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
    cout << SIZE(v) << " ";
    for (int a : v) cout << a << " ";
    cout << "\n";
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