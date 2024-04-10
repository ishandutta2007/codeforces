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

const int kP = 6;

VI primes = {1000000007,
             1000000009,
             1000000021,
             1000000033,
             1000000087,
             1000000093};

string s;


int pot[6][1000006];
int revpot[6][1000006];
int hasz[6][1000006];

int qpot(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b % 2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

int inv(int a, int mod){
    return qpot(a, mod - 2, mod);
}

void build_primez() {
    REP(i, kP){
        pot[i][0] = 1;
        FOR(j, 1, SIZE(s)) pot[i][j] = (pot[i][j - 1] * 10) % primes[i];

        revpot[i][0] = 1;
        int dupa = inv(10, primes[i]);
        FOR(j, 1, SIZE(s)) revpot[i][j] = (revpot[i][j - 1] * dupa) % primes[i];

        FORD(j, SIZE(s) - 1, 0) {
            hasz[i][j] = (hasz[i][j + 1] + (s[j] - '0') * pot[i][SIZE(s) - j - 1]) % primes[i];
        }
    }
}

bool add_shit(int pocz1, int kon1,
              int pocz2, int kon2,
              int pocz3, int kon3) {

    int a = max({kon1 - pocz1, kon2 - pocz2, kon3 - pocz3}) + 1;
    int zostalo = 0;
    while (a--) {
        int dis = zostalo;
        if (kon1 >= pocz1) dis += (s[kon1] - '0');
        if (kon2 >= pocz2) dis += (s[kon2] - '0');
        int bla = 0;
        if (kon3 >= pocz3) bla = (s[kon3] - '0');
        if (dis % 10 != bla) return false;
        zostalo = dis / 10;
        kon1--;
        kon2--;kon3--;
    }
    return true;
}

bool check_candidate(int pocz1, int kon1, int pocz2, int kon2, int pocz3, int kon3) {
//cerr << pocz1 << " " << kon1 << " | "<< pocz2 << " " << kon2 << " | "<< pocz3 << " " << kon3 << "\n";
    if (s[pocz2] == '0' && pocz2 != kon2) return false;
    if (s[pocz3] == '0' && pocz3 != kon3) return false;

    REP(i, kP) {
        int mod1 = (hasz[i][pocz1] - hasz[i][kon1 + 1] + primes[i]) % primes[i];
        mod1 *= revpot[i][SIZE(s) - kon1];
        mod1 %= primes[i];

        int mod2 = (hasz[i][pocz2] - hasz[i][kon2 + 1] + primes[i]) % primes[i];
        mod2 *= revpot[i][SIZE(s) -kon2];
        mod2 %= primes[i];

        int mod3 = (hasz[i][pocz3] - hasz[i][kon3 + 1] + primes[i]) % primes[i];
        mod3 *= revpot[i][SIZE(s) -kon3];
        mod3 %= primes[i];
        //cerr << mod1 << " " << mod2 << " " << mod3 << "\n";

        if ((mod1 + mod2 - mod3) % primes[i] != 0) return false;
    }

   // cerr << "check_candidate TRUE\n" << pocz1 << " " << kon1 << " | "<< pocz2 << " " << kon2 << " | "<< pocz3 << " " << kon3 << " | ";

    return true;
}

void wypisz(int pocz1, int kon1, int pocz2, int kon2, int pocz3, int kon3) {
    for (int i = pocz1; i <= kon1; i++) cout << s[i];
    cout << "+";
    for (int i = pocz2; i <= kon2; i++) cout << s[i];
    cout << "=";
    for (int i = pocz3; i <= kon3; i++) cout << s[i];
    cout << "\n";
    return;
}


void jebaj() {

    cin >> s;
    if (s[0] == '0') {
        cout << "0+";
        FOR(i, 1, SIZE(s) / 2) cout << s[i];
        cout << "=";
        FOR(i, 1, SIZE(s) / 2) cout << s[i];
        cout << "\n";
        return;
    }

    build_primez();

    int pocz1, kon1, pocz2, kon2, pocz3, kon3;

    for (int x = 1; x <= SIZE(s) / 2; x++) {
        pocz1 = 0;
        kon1 = x - 1;
        pocz2 = x;

        kon3 = SIZE(s) - 1;
        pocz3 = SIZE(s) - x;
        kon2 = pocz3 - 1;

        if (kon2 >= pocz2 && kon2 - pocz2 + 1 <= x) {
            if (check_candidate(pocz1, kon1, pocz2, kon2, pocz3, kon3)){
                if (add_shit(pocz1, kon1, pocz2, kon2, pocz3, kon3)) {
                        wypisz(pocz1, kon1, pocz2, kon2, pocz3, kon3);
                            return;
                }
            }
        }
    }

    for (int x = 2; x <= SIZE(s) / 2; x++) {
        pocz1 = 0;
        kon1 = x - 2;
        pocz2 = x - 1;

        kon3 = SIZE(s) - 1;
        pocz3 = SIZE(s) - x;
        kon2 = pocz3 - 1;

        if (kon2 >= pocz2 && kon2 - pocz2 + 1 <= x) {
            if (check_candidate(pocz1, kon1, pocz2, kon2, pocz3, kon3)){
                if (add_shit(pocz1, kon1, pocz2, kon2, pocz3, kon3)) {
                        wypisz(pocz1, kon1, pocz2, kon2, pocz3, kon3);
                            return;
                }
            }
        }
    }


    for (int x = 1; x <= SIZE(s) / 2; x++) {

        kon3 = SIZE(s) - 1;
        pocz3 = SIZE(s) - x;
        kon2 = pocz3 - 1;
        pocz2 = kon2 - x + 1;
        kon1 = pocz2 - 1;
        pocz1 = 0;

        if (kon1 >= pocz1 && kon1 - pocz1 + 1 <= x) {
            if (check_candidate(pocz1, kon1, pocz2, kon2, pocz3, kon3)){
                if (add_shit(pocz1, kon1, pocz2, kon2, pocz3, kon3)) {
                        wypisz(pocz1, kon1, pocz2, kon2, pocz3, kon3);
                            return;
                }
            }
        }
    }

    for (int x = 2; x <= SIZE(s) / 2; x++) {

        kon3 = SIZE(s) - 1;
        pocz3 = SIZE(s) - x;
        kon2 = pocz3 - 1;
        pocz2 = kon2 - x + 2;
        kon1 = pocz2 - 1;
        pocz1 = 0;

        if (kon1 >= pocz1 && kon1 - pocz1 + 1 <= x) {
            if (check_candidate(pocz1, kon1, pocz2, kon2, pocz3, kon3)){
                if (add_shit(pocz1, kon1, pocz2, kon2, pocz3, kon3)) {
                        wypisz(pocz1, kon1, pocz2, kon2, pocz3, kon3);
                            return;
                }
            }
        }
    }

    assert(false);
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