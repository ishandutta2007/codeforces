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
typedef vector<PII> VII;

int licz(int n, int k) {
    if (k == 1) return (n * (n + 1)) / 2;
    if (k == n) return 1;
    return n / k + k * (n / k) * (n / k - 1) / 2;
}

void jebaj() {
    int n;
    cin >> n;
    VI res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.PB(licz(n, i));
            if (i * i != n) res.PB(licz(n, n / i));
        }
    }
    sort(ALL(res));
    for (int a : res)cout << a << " "; cout << "\n";
}

#undef int
int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}