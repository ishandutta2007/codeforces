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

int zapytaj(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    int k;
    cin >> k;
    return k % 2;
}

void wypisz(int a, int b, int c, int d) {
    cout << "! " << a << " " << b << " " << c << " " << d << endl;
    return;
}

PII binsercz(int x1, int y1, int x2, int y2) {
    while (x1 < x2 || y1 < y2) {
        int x_mid = (x1 + x2) / 2;
        int y_mid = (y1 + y2) / 2;
        if (zapytaj(x1, y1, x_mid, y_mid)) {
            x2 = x_mid;
            y2 = y_mid;
        } else {
            if (x1 < x2) x1 = x_mid + 1;
            else x1 = x_mid;
            if (y1 < y2) y1 = y_mid + 1;
            else y1 = y_mid;
        }
    }
    return {x1, y1};
}

void jebaj() {
    int n;
    cin >> n;
    VI wiersze, kolumny;
    for (int i = 1; i <= n; i++) {
        if (zapytaj(i, 1, i, n)) wiersze.PB(i);
        if (zapytaj(1, i, n, i)) kolumny.PB(i);
    }
    if (!wiersze.empty() && !kolumny.empty()) {
            VII v;
        for (int x : wiersze) for (int y : kolumny) if (zapytaj(x, y, x, y)) {
            v.EB(x, y);
        }
        wypisz(v[0].ST, v[0].ND, v[1].ST, v[1].ND);
        return;
    }
    if (kolumny.empty()) {
        int nr = wiersze[0];
        PII p = binsercz(nr, 1, nr, n);
        wypisz(p.ST, p.ND, wiersze[1], p.ND);
    } else {
        int nr = kolumny[0];
        PII p = binsercz(1, nr, n, nr);
        wypisz(p.ST, p.ND, p.ST, kolumny[1]);
    }
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