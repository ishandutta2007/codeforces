#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    vector<string> atoms;
    atoms.pb("H");
    atoms.pb("He");
    atoms.pb("Li");
    atoms.pb("Be");
    atoms.pb("B");
    atoms.pb("C");
    atoms.pb("N");
    atoms.pb("O");
    atoms.pb("F");
    atoms.pb("Ne");
    atoms.pb("Na");
    atoms.pb("Mg");
    atoms.pb("Al");
    atoms.pb("Si");
    atoms.pb("P");
    atoms.pb("S");
    atoms.pb("Cl");
    atoms.pb("Ar");
    atoms.pb("K");
    atoms.pb("Ca");
    atoms.pb("Sc");
    atoms.pb("Ti");
    atoms.pb("V");
    atoms.pb("Cr");
    atoms.pb("Mn");
    atoms.pb("Fe");
    atoms.pb("Co");
    atoms.pb("Ni");
    atoms.pb("Cu");
    atoms.pb("Zn");
    atoms.pb("Ga");
    atoms.pb("Ge");
    atoms.pb("As");
    atoms.pb("Se");
    atoms.pb("Br");
    atoms.pb("Kr");
    atoms.pb("Rb");
    atoms.pb("Sr");
    atoms.pb("Y");
    atoms.pb("Zr");
    atoms.pb("Nb");
    atoms.pb("Mo");
    atoms.pb("Tc");
    atoms.pb("Ru");
    atoms.pb("Rh");
    atoms.pb("Pd");
    atoms.pb("Ag");
    atoms.pb("Cd");
    atoms.pb("In");
    atoms.pb("Sn");
    atoms.pb("Sb");
    atoms.pb("Te");
    atoms.pb("I");
    atoms.pb("Xe");
    atoms.pb("Cs");
    atoms.pb("Ba");
    atoms.pb("La");
    atoms.pb("Ce");
    atoms.pb("Pr");
    atoms.pb("Nd");
    atoms.pb("Pm");
    atoms.pb("Sm");
    atoms.pb("Eu");
    atoms.pb("Gd");
    atoms.pb("Tb");
    atoms.pb("Dy");
    atoms.pb("Ho");
    atoms.pb("Er");
    atoms.pb("Tm");
    atoms.pb("Yb");
    atoms.pb("Lu");
    atoms.pb("Hf");
    atoms.pb("Ta");
    atoms.pb("W");
    atoms.pb("Re");
    atoms.pb("Os");
    atoms.pb("Ir");
    atoms.pb("Pt");
    atoms.pb("Au");
    atoms.pb("Hg");
    atoms.pb("Tl");
    atoms.pb("Pb");
    atoms.pb("Bi");
    atoms.pb("Po");
    atoms.pb("At");
    atoms.pb("Rn");
    atoms.pb("Fr");
    atoms.pb("Ra");
    atoms.pb("Ac");
    atoms.pb("Th");
    atoms.pb("Pa");
    atoms.pb("U");
    atoms.pb("Np");
    atoms.pb("Pu");
    atoms.pb("Am");
    atoms.pb("Cm");
    atoms.pb("Bk");
    atoms.pb("Cf");
    atoms.pb("Es");
    atoms.pb("Fm");

    map<string, int> w;
    for (int i = 0; i < sz(atoms); ++i) {
        w[atoms[i]] = i + 1;
    }

    int n, m;
    cin >> n >> m;

    vector<string> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }

    vector<pii> dp(1 << n, {-1, -1});
    vector<int> p(1 << n);
    dp[0] = {0, 0};
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (dp[mask].first == -1) {
            continue;
        }
        int id = dp[mask].first;
        for (int i = 0; i < n; ++i) {
            if (bit(mask, i)) {
                continue;
            }
            if (dp[mask].second + w[a[i]] > w[b[id]]) {
                continue;
            }
            if (dp[mask].second + w[a[i]] == w[b[id]]) {
                dp[mask + (1 << i)] = {id + 1, 0};
                p[mask + (1 << i)] = i;
            } else {
                dp[mask + (1 << i)] = {id, dp[mask].second + w[a[i]]};
                p[mask + (1 << i)] = i;
            }
        }
    }

    if (dp[(1 << n) - 1].first != m || dp[(1 << n) - 1].second != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    vector<int> order;
    int curr = (1 << n) - 1;
    while (curr) {
        order.pb(p[curr]);
        curr ^= (1 << p[curr]);
    }

    reverse(all(order));
    int sum = 0;
    int j = 0;
    for (int i = 0; i < sz(order); ++i) {
        int id = order[i];
        cout << a[id];
        sum += w[a[id]];
        if (sum == w[b[j]]) {
            cout << "->" << b[j] << "\n";
            sum = 0;
            ++j;
        } else {
            cout << "+";
        }
    }

}