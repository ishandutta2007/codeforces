// Hydro submission #62a06275ab7be5564ed00f12@1654678134470
#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")//drop avx and fma if RE#1

using namespace std;

using ll = long long;

#define ILIKEGENTOO
#ifdef ILIKEGENTOO
void E(){}template<class A,class...B>void E(A $,B..._){cerr<<' '<<$;E(_...);}
# define E($...) E(#$,'=',$,'\n')
#else
# define E($...)
#endif

#define Sz(x) ((int) x.size())

using ld = double;

int caseNo = 1;

const double pi = acos(-1);

const int mod = 998244353;

const int INFi = 1e9+7;

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> minR(n+1,INFi);
    set<int> keks;
    for (int i=0;i<n;i++) {
        keks.insert(i);
    }
    map<int, int> known;
    for (int i=0;i<q;i++) {
        int t;
        cin >> t;
        if (t==0) {
            int l,r,x;
            cin >> l >> r >> x;
            l--; r--;
            if (x==1) {
                auto ptr = keks.lower_bound(l);
                assert(ptr!=keks.end());

                minR[*ptr] = min(minR[*ptr], r);
                int nexter = next(ptr)!=keks.end() ? *next(ptr) : n;
                if (minR[*ptr] < nexter) {
                    known[*ptr] = 1;
                }
            } else {
                auto nxt = keks.upper_bound(r);
                while (true) {
                    auto ptr = keks.lower_bound(l);
                    if (ptr == keks.end() || *ptr > r) break;
                    known[*ptr] = 0;
                    if (nxt!=keks.end()) {
                        minR[*nxt] = min(minR[*nxt], minR[*ptr]);
                    }
                    keks.erase(*ptr);
                }
                if (nxt!=keks.end()) {
                    int nxtNxt = next(nxt)!=keks.end() ? *next(nxt): n;
                    if (minR[*nxt] < nxtNxt) {
                        known[*nxt] = 1;
                    }
                }
                auto prv = keks.lower_bound(l);
                if (prv!=keks.begin()) {
                    prv = prev(prv);
                    int prvNxt = next(prv)!=keks.end() ? *next(prv) : n;
                    if (minR[*prv] < prvNxt) {
                        known[*prv] = 1;
                    }
                }
            }
            continue;
        }
        assert(t==1);
        int id;
        cin >> id;
        id--;
        if (!known.count(id)) {
            cout << "N/A\n";
            continue;
        }
        if (known.at(id)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    //    testgen();
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t = 1;
//        cin >> t;
    for (int i=0;i<t;i++) {
        solve();
    }
    return 0;
}