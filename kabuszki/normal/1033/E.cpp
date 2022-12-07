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

int zapytanie_przedzial(int w, const VI& v, int pocz, int kon) {
    int ile = 0;
    FOR(i, pocz, kon - 1) {
        if (v[i] > 0) ile++;
    }
    if (ile == 0) return -1;
    cout << "? " << ile << endl;
    FOR(i, pocz, kon - 1) {
        if (v[i] > 0) cout << v[i] << " ";
    }
    cout << endl;
    int ans;
    cin >> ans;
    if (ans == -1) exit(0);
    return ans;
}

int zapytanie_przedzial_z_w(int w, const VI& v, int pocz, int kon) {
    int ile = 1;
    FOR(i, pocz, kon - 1) {
        if (v[i] > 0) ile++;
    }
    cout << "? " << ile << endl;
    cout << w << " ";
    FOR(i, pocz, kon - 1) {
        if (v[i] > 0) cout << v[i] << " ";
    }
    cout << endl;
    int ans;
    cin >> ans;
    if (ans == -1) exit(0);
    return ans;
}

int znajdz_krawedz_z_wierzcholka(int w, VI& v) {
    int pocz = 1, kon = SIZE(v);
    if (zapytanie_przedzial(w, v, pocz, kon) ==
        zapytanie_przedzial_z_w(w, v, pocz, kon)) return -1;

    while (pocz + 1 < kon) {
            int mid = (pocz + kon) / 2;
        int a = zapytanie_przedzial(w, v, pocz, mid);
        if (a == -1) {
            pocz = mid;
            continue;
        }

        int b = zapytanie_przedzial_z_w(w, v, pocz, mid);
        if (a == b) pocz = mid;
        else kon = mid;
    }
    return pocz;
}

void dfs(int a, const vector<VI>& graf, VI& kolor, VI& parent, int parent_k) {

    kolor[a] = 3 - parent_k;
    for (int b : graf[a]) if (kolor[b] == 0) {
            parent[b] = a;
        dfs(b, graf, kolor, parent, kolor[a]);
    }
}

void ujeb(VI v, VI parent) {

    if (zapytanie_przedzial(-1, v, 0, SIZE(v)) == 0) return;

    int a, b, d;

    FORD(i, SIZE(v), 0) {
        if (zapytanie_przedzial(-1, v, 0, i) == 0) {
            b = v[i];
            d = i;
            break;
        }
    }
    FOR(i, 0, b) {
        if (zapytanie_przedzial(-1, v, i, d + 1) == 0) {
            a = v[i - 1];
            break;
        }
    }

    //cerr << "a = " << a << " b = " << b << endl;

    VI x, y;
    x.PB(a);
    while (true) {
        if (parent[x.back()] == 0) break;
        x.PB(parent[x.back()]);
    }
    y.PB(b);
    while (true) {
        if (parent[y.back()] == 0) break;
        y.PB(parent[y.back()]);
    }

    int common_root;
    while(true) {
        if (x.empty() || y.empty() || x.back() != y.back()) break;
        else {
            common_root = x.back();
            x.pop_back();
            y.pop_back();
        }
    }
    x.PB(common_root);
    reverse(ALL(y));
    cout << "N " << SIZE(x) + SIZE(y) << endl;
    for (int a : x)cout << a << " ";
    for (int a : y) cout << a << " ";
    cout << endl;
    exit(0);
}

void jebaj() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "Y 1" << endl;
        cout << 1 << endl;
        return;
    }

    set<int> znane, nieznane;
    VI do_zapytan({0, 1});
    FOR(i, 2, n) {
        nieznane.insert(i);
        do_zapytan.PB(i);
    }
    znane.insert(1);
    do_zapytan[1] = 0;

    vector<VI> graf(n + 1);
    VI kolor(n + 1), parent(n+1);

    while (!nieznane.empty()) {
        int a = *znane.begin();
        int new_edge = znajdz_krawedz_z_wierzcholka(a, do_zapytan);
        if (new_edge == -1) {
            znane.erase(a);
            continue;
        }
        nieznane.erase(new_edge);
        znane.insert(new_edge);
        do_zapytan[new_edge] = 0;
        graf[a].PB(new_edge);
        graf[new_edge].PB(a);
    }

    dfs(1, graf, kolor, parent, 2);

    VI x, y;
    FOR(i, 1, n) {
        if (kolor[i] == 1) x.PB(i);
        else y.PB(i);
    }
    //cerr << "parents "; FOR(i, 1, n) cerr << parent[i] << " "; cerr << endl;
    ujeb(x, parent);
    ujeb(y, parent);
    cout << "Y " << SIZE(x) << endl;
    for (int a : x) cout << a << " "; cout << endl;
    return;


}
int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    int t;
    t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}