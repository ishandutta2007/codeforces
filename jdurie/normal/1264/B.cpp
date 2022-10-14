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
#define F(i, l, r) for(ll i = l; i - r; i < r ? i++ : i--)
#define P(a) { cout << #a << " "; for(auto _ : a) cout << _ " "; cout << endl; }
#define PN(a, n) { cout << #a << " "; F(_, 0, n) cout << a[_] << " "; cout << endl; }
#define CE(a, x) lower_bound(a.begin(), a.end(), x)
#define UP(a, x) upper_bound(a.begin(), a.end(), x)
#define FL(a, x) (x < *a.begin() ? a.end() : --UP(a, x))
#define LO(a, x) (x <= *a.begin() ? a.end() : --CE(a, x))
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 100010

ll a[4], x[4], ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    F(i, 0, 4) { cin >> x[i]; a[i] = x[i]; }
    for(ll c = 0; c < 4; c++)
        if(a[c]) {
            ans[0] = c;
            a[c]--;
            ll i = 1;
            bool b = true;
            //cout << "0 " << ans[0] << endl;
            while(a[0] + a[1] + a[2] + a[3]) {
                if(ans[i - 1] && a[ans[i - 1] - 1]) {
                    ans[i] = ans[i - 1] - 1;
                    a[ans[i - 1] - 1]--;
                } else if(ans[i - 1] != 3 && a[ans[i - 1] + 1]) {
                    ans[i] = ans[i - 1] + 1;
                    a[ans[i - 1] + 1]--;
                } else { b = false; break; } 
                //cout << i << " " << ans[i] << endl;
                i++;
            }
            if(b) {
                cout << "YES" << endl;
                for(ll j = 0; j < i; j++)
                    cout << ans[j] << " ";
                return 0;
            }
            F(i, 0, 4) a[i] = x[i];
        }
    cout << "NO" << endl;
}