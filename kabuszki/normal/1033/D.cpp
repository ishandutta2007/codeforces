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

VI sprawdz(int a) {

    int b;
    b = pow(a, 1.0/3.0);
    if (b * b * b == a) return VI({b, b, b});
    b++;
    if (b * b * b == a) return VI({b, b, b});
    b-=2;
    if (b * b * b == a) return VI({b, b, b});
    b++;
    b = pow(a, 1.0/4.0);
    if (b * b * b * b == a) return VI({b, b, b, b});
    b++;
    if (b * b * b * b == a) return VI({b, b, b, b});
    b-=2;
    if (b * b * b * b == a) return VI({b, b, b, b});
    b++;

    b = sqrt(a);
    if (b * b == a) return VI({b, b});
    b++;
    if (b * b == a) return VI({b, b});
    b-=2;
    if (b * b == a) return VI({b, b});
    b++;

    return VI();
}



void jebaj() {

    int n;
    cin >> n;
    unordered_map<int, int> pq;
    unordered_map<int, int> primes;
    REP(i, n) {
        int a;
        cin >> a;
        auto v = sprawdz(a);
        if (v.empty()) {
            pq[a]++;
        } else {
            for (int b : v) primes[b]++;
        }
    }

    VI dupa;
    for(auto p : pq) dupa.PB(p.ST);

    REP(i, SIZE(dupa)) {
        REP(j, i) {
            int a = dupa[i], b = dupa[j];
            if (a > 0 && b > 0) {
                int c = __gcd(a, b);
                if (c > 1) {
                    primes[c] += pq[a];
                    primes[a / c] += pq[a];
                    primes[c] += pq[b];
                    primes[b / c] += pq[b];
                    dupa[i] = 0;
                    dupa[j] = 0;
                }
            }
        }
    }

    int res = 1;
    int mod = 998244353;
    for (int a : dupa) if (a != 0) {
        bool mykd = false;
        for (auto p : primes) {
            if (a % p.ST == 0) {
                primes[p.ST] += pq[a];
                primes[a / p.ST] += pq[a];
                mykd = true;
                break;
            }
        }
        if (!mykd) {
            res *= (pq[a] + 1);
            res %= mod;
            res *= (pq[a] + 1);
            res %= mod;
        }
    }

    for (auto p : primes) {
        res = (res * (p.ND + 1)) % mod;
    }

    cout << res << endl;
    cout.flush();
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