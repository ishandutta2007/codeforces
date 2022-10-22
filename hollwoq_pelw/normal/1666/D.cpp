#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

string s, t;

vi vpos[26];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> s >> t;

    bool ans = 1;
    For(c, 0, 26){
        vpos[c].clear();
    }
    For(i, 0, isz(s)){
        vpos[s[i] - 'A'].emplace_back(i);
    }
    vi vpost;
    Fora(c, t){
        if (vpos[c - 'A'].empty()){
            ans = 0;
            break;
        }
        vpost.emplace_back(vpos[c - 'A'].back());
        vpos[c - 'A'].pop_back();
    }
    if (!ans){
        cout << "NO" << endl;
        continue;
    }
    sort(bend(vpost));
    string tt;
    Fora(i, vpost){
        tt += s[i];
    }
    if (tt != t){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/