#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;

const int INF = 1000000009;

int ile(int kon, int a, int r) {
    if (kon < 0) return 0;
    int res = kon / a;
    int dupka = kon % a;
    if (dupka >= r) res++;
    return res;
}

int sum(int kon, int a, int r) {
    if (kon < r) return 0;
    int pocz = r;
    int dupka = kon % a;
    int nkon = 0;
    if (dupka >= r) nkon = kon - dupka + r;
    else nkon = kon - dupka - a + r;


    int chuj = nkon / a;
    return (chuj + 1) * r + a * chuj * (chuj + 1) / 2;
}

int S(int pocz, int kon, int a, int r) {

    return (ile(kon, a, r) - ile(pocz - 1, a, r)) * (kon + 1) - sum(kon, a, r) + sum(pocz - 1, a, r);

}

int licz(int pocz, int kon, int a, int r) {

    if (pocz > kon) return 0;
    int chuj = pocz / a;
    if (pocz % a > r) chuj++;
    return (chuj) * (kon - pocz + 1) + S(pocz, kon, a, r);

}

void jebaj() {
    int m, a, b;
    cin >> m >> a >> b;
    VI kiedy_mozna_dostac_reszte(a, INF);
    kiedy_mozna_dostac_reszte[0] = 0;
    int pos = 0, last = 0;
    while (true) {
        if (pos < b) {
            pos += ((b - pos) / a) * a;
        }
        while (pos < b) pos += a;
        int x = pos;
        while (x - b > 0) {
            x -= b;
            kiedy_mozna_dostac_reszte[x] = max(pos, last);
            last = kiedy_mozna_dostac_reszte[x];
        }
        if (x == b) break;
        pos = x;
    }

    int wynik = 0;
    VI vv;
    REP(i, a) {

        int r = kiedy_mozna_dostac_reszte[i];
     //   cerr << r << " ";
        int x = licz(r, m, a, i);
        vv.PB(x);
        wynik += x;

    }
  //  cerr << "\n";
  //  for (int a : vv) cerr << a << " "; cerr <<"\n";
    cout << wynik << "\n";
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