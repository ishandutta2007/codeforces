#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> iipair;
typedef pair <ll,ll> llpair;

const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const double EPS = 1e-8;

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
const double PI = acos(-1.0);

const ll MOD = 1000000007;
ll n, a, p[200000],ansarro[200000],ansarre[200000];
vector<ll> sons[200000];
llpair ans(ll x) {
    ll sume = 0ll;
    ll sumo = -IINF;
    llpair tmp;
    //cout << x << endl;
    for (int i = 0; i < sons[x].size(); ++i) {
        tmp = ans(sons[x][i]);
        ll sumox = max(sumo + tmp.first, sume + tmp.second);
        sume = max(sume + tmp.first, sumo + tmp.second);
        sumo = sumox;
        //if (x == 4) cout << tmp.first << ' ' << tmp.second<< endl;
        //if (x == 4) cout << sumo << ' ' << sume << endl;
    };
    //if (x == 4) cout << sumo << ' ' << sume << endl;
    sumo = max(sumo, sume + p[x]);
    ansarro[x] = sumo;
    ansarre[x] = sume;
    return mp(sume, sumo);
};
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0;i < n; ++i) {
        cin >> a >> p[i];
        if (a != -1) sons[a - 1].pb(i);
    };
    llpair tmp = ans(0);
    ll rez = tmp.first;
    rez = 0;
    for (int i = 0; i < n; ++i) rez = max(rez, ansarro[i]);
    for (int i = 0; i < n; ++i) rez = max(rez, ansarre[i]);
    //for (int i = 0; i < n; ++i) cout << ansarro[i] << endl;
    //for (int i = 0; i < n; ++i) cout << ansarre[i] << endl;
    cout << rez;
    return 0;
};