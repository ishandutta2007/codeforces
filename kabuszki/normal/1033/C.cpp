#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
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
    VI v(n + 1), pos(n+1), wygryw(n+1);
    FOR(i, 1, n) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    wygryw[pos[n]] = 2;
    FORD(i, n - 1, 1) {
        int p = pos[i];
        wygryw[p] = 2;
        for (int j = p + i; j <= n; j += i) {
            if (v[j] > i && wygryw[j] == 2) wygryw[p] = 1;
        }
        for (int j = p - i; j >= 1; j -= i) {
            if (v[j] > i && wygryw[j] == 2) wygryw[p] = 1;
        }
    }
    FOR(i,1,n) if (wygryw[i] == 1) cout << "A"; else cout << "B";
    cout << "\n";

}
int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}