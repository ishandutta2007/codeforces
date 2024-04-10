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

int licz(int n, int a) {
    if (n + (n - 1) < a) return 0;
    if (n >= a) {
        return a / 2;
    }
    else {
        int k = a - n;
        return (n - k + 1) / 2;
    }
}

void jebaj() {
    int n;
    cin >> n;
    if (n < 5) {
        cout << ((n * (n - 1) ) / 2) << "\n";
        return;
    }

    int a = 10;
    while (n + (n - 1) >= a - 1) {
        a *= 10;
    }
    a /= 10;
    int res = 0;
    FOR(i, 0, 9) {
        res += licz(n, i * a + (a - 1));
    }
    cout << res << "\n";

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