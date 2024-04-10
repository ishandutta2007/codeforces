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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;



void jebaj() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i <= (n / a); i++) {
        if ((n - i * a) % b == 0) {
            cout << "YES\n";
            cout << i << " " << (n - i * a) / b << "\n";
            return;
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