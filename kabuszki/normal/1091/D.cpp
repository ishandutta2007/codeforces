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
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;

const int mod = 998244353;

int qpot(int a, int b) {

    int res = 1;
    while (b) {
        if (b % 2) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;

}

void jebaj() {
    int n;
    cin >> n;
    VI silnia(n + 1);
    silnia[0] = 1;
    FOR(i,1 , n) silnia[i] = (silnia[i - 1] * i) % mod;
    VI rev_silnia(n + 1);
    rev_silnia.back() = qpot(silnia.back(), mod - 2);
    FORD(i, n - 1, 0) rev_silnia[i] = (rev_silnia[i + 1] * (i + 1)) % mod;

    int dupa = 0;
    FOR(k, 1, n - 2) {
        int a = k * (n - k - 1);
        a %= mod;
        a = (a * rev_silnia[n - k]) % mod;
        dupa = (dupa + a) % mod;
    }
    dupa = (dupa * silnia[n]) % mod;
    cout << (silnia[n] + dupa) % mod << "\n";
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