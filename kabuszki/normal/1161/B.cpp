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


void jebaj() {
    int n, m;
    cin >> n >> m;
    vector<VI> dupa(n+1);
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int len = b - a;
        if (len * 2 > n) {
            len = n - len;
            swap(a, b);
        }
        dupa[len].PB(a);
    }

    set<int> secik;
    FOR(i, 1, n/2) if(n % i == 0) secik.IN(i);

    FOR(i, 1, n) if (!dupa[i].empty()) {
        //for (int a : dupa[i]) cerr << a << " "; cerr << "\n";
        if (SIZE(dupa[i]) == 1 && (i * 2 != n)) {
            cout << "No\n";
            return;
        }
        VI tmp;
        for (int a: secik) {
            VI w = dupa[i];
          //  cerr << a << "\n";
            for (int& b : w) b = b % a;
            sort(ALL(w));
            int pos = 1;
            int ile = 1;
            bool ok = true;
            w.PB(-1);
            while (pos < SIZE(w)) {
              //  cerr << pos << " " << a << " " << w[pos] << "\n";
                if (w[pos] == w[pos - 1]) ile++;
                else {
                    if (ile * a != n) {
                        ok = false;
                        break;
                    }
                    ile = 1;
                }
                pos++;
            }
            if (!ok && (i * 2 != n || a * 2 != n)) tmp.PB(a);
        }
        for (auto a : tmp) secik.ER(a);

    }
    if (secik.empty()) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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