
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

const int M = 1 << 18;
int dp[2 * M];

int zapytaj(int pocz, int kon) {
    if (pocz > kon) return 0;
    pocz += M;
    kon += M;
    int res = dp[pocz];
    if (kon != pocz) {
        res += dp[kon];
    }
    while (pocz / 2 != kon / 2) {
        if (!(pocz & 1)) res += dp[pocz ^ 1];
        if (kon & 1) res += dp[kon ^ 1];
        pocz >>= 1;
        kon >>= 1;
    }
    return res;
}

void wstaw(int pos) {
    pos += M;
    while (pos) {
        dp[pos]++;
        pos >>= 1;
    }
}



struct chuj {
    int pos;
    bool fake;

    chuj(int p, int f) : pos(p), fake(f) {}

    int get_pos() const {
        if (fake) return pos;
        return pos - zapytaj(0, pos - 1);
    }
};

struct kurwa {

bool operator() (const chuj& a, const chuj& b) {
    if (!a.fake && !b.fake) return a.pos < b.pos;
    return a.get_pos() < b.get_pos();
}

};

set<chuj, kurwa> secik[256];

void jebaj() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    REP(i, n) {
        secik[s[i]].insert(chuj(i, 0));
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        char c;
        cin >> c;
        //cerr << (int)c << "\n";
        chuj fake(r, 1);

        while (true) {
            if (secik[c].empty()) break;
            auto it = secik[c].upper_bound(fake);
            if (it == secik[c].begin()) break;
            it--;
            int a = it->get_pos();
            if (a < l) break;
            fake.pos = a - 1;
            //cerr << "usuwam " << a << " " << (char)c << "\n";
            wstaw(it->pos);
            secik[c].erase(it);
        }

    }

    vector<char> ple(n);
    REP(i, 256) {
        for (auto& a : secik[i]) {
                int pos = a.get_pos();
        //cerr << (char)i << " " << pos << "\n";
                ple[pos] = (char)i;
        }
    }

    for (char c : ple) {
        if (c == 0) break;
        cout << c;
    }
    cout << "\n";
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