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
typedef long long LL;


void jebaj() {

    LL a, b;
    cin >> b >> a;
    if (b != a + 1) {
        cout << "NO\n";
        return;
    }
    b = b + a;
    for (LL p = 3; p * p <= b; p+=2) {
        if (b % p == 0) {
        cout << "NO\n";
        return;

        }
    }
        cout << "YES\n";
        return;

}
int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    int t;
    cin >> t;
    while (t--) {
        jebaj();
    }
    return 0;
}