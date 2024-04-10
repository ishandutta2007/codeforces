#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
template<class T, class S>
ostream& operator << (ostream &o, const pair<T, S> &p) {
    return o << '(' << p.first << ", " << p.second << ')';
}

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef complex<ld> pt;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i != r; l < r ? i++ : i--)
#define P(a) { cout << #a << ": { "; for(auto _ : a) cout << _ << " "; cout << "}" << endl; }
#define PN(a, n) { cout << #a << ": { "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define CE(a, x) lower_bound(a.begin(), a.end(), x)
#define UP(a, x) upper_bound(a.begin(), a.end(), x)
#define FL(a, x) (x < *a.begin() ? a.end() : --UP(a, x))
#define LO(a, x) (x <= *a.begin() ? a.end() : --CE(a, x))
#define MC(a, x) a.lower_bound(x)
#define MU(a, x) a.upper_bound(x)
#define MF(a, x) (x < (*a.begin()).K ? a.end() : --MU(a, x))
#define ML(a, x) (x <= (*a.begin()).K ? a.end() : --MC(a, x))
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 200010

ll n, g[N];

void doTheThing(string a) {
    set<ll> st;
    F(i, 0, n) {
        if(!st.empty() && a[i] != '<') {
            for(ll x : st) cout << x << " ";
            st.clear();
        }
        if(a[i] == '<') st.insert(g[i]);
        else cout << g[i] << " ";
    }
    if(!st.empty()) for(ll x : st) cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        cin >> n;
        GS(a) a = '<' + a;
        ll lCt = 0; F(i, 0, n) if(a[i] == '<') lCt++;
        ll m1 = n, m2 = n - lCt;
        F(i, 0, n) g[i] = a[i] == '<' ? m1-- : m2--;
        doTheThing(a);
        m1 = n - lCt + 1; m2 = m1 - 1;
        F(i, 0, n) g[i] = a[i] == '<' ? m1++ : m2--;
        doTheThing(a);
    }
}