#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

#define int long long
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) Fora(iiii, a) cout << iiii << ' '; cout << endl;
#define PrintVl(a) Fora(iiii, a) cout << iiii << endl;
#define PrintA(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){ string _sDEB = #args; replace(_sDEB.begin(), _sDEB.end(), ',', ' '); stringstream _ssDEB(_sDEB); istream_iterator<string> _itDEB(_ssDEB); DEB(_itDEB, args); }
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
    cout << *it << " = " << a << endl;
    DEB(++it, args...);
}
*/

// Functions

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a))
#define mset1(a) memset(a, 1, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
#define y0 _y0_
#define y1 _y1_
#define div divi
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 2e5 + 5, M = log2(N) + 1, K = 1e3 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int a[N], b[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q = 1;
cin >> q;
while (q--){
    int n, l, r;
    cin >> n >> l >> r;
    a[1] = 1;
    a[2] = (n - 2) * 2;
    ForE(i, 1, n - 2){
        a[i * 2 + 1] = 1;
        a[i * 2 + 2] = (n - 2 - i + 1) * 2 - 1;
    }
    a[2 * n - 1] = 1;
    a[2 * n] = 1;
    ForE(i, 1, 2 * n){
        b[i] = b[i - 1] + a[i];
    }
    int segl, segr;
    ForE(i, 1, 2 * n){
        if (b[i - 1] < l && l <= b[i]){
            segl = i;
        }
        if (b[i - 1] < r && r <= b[i]){
            segr = i;
            break;
        }
    }
    // cout << segl << ' ' << segr << endl;
    if (segl == segr){
        if (segl == 1) cout << 1 << ' ';
        else if (segl == 2){
            ForE(i, 1, a[segl]){
                if (l <= i + b[segl - 1] && i + b[segl - 1] <= r){
                    if (i % 2 == 0) cout << 1 << ' ';
                    else cout << i / 2 + 2 << ' ';
                }
            }
        }
        else if (segl == 2 * n - 1) cout << n << ' ';
        else if (segl == 2 * n) cout << 1 << ' ';
        else if (segl % 2 == 1) cout << n << ' ';
        else{
            ForE(i, 1, a[segl]){
                if (l <= i + b[segl - 1] && i + b[segl - 1] <= r){
                    if (i % 2 == 1) cout << segl / 2 << ' ';
                    else cout << segl / 2 + i / 2 << ' ';
                }
            }
        }
        cout << endl;
        continue;
    }
    if (segl == 1) cout << 1 << ' ';
    else if (segl == 2){
        ForE(i, 1, a[segl]){
            if (l <= i + b[segl - 1]){
                if (i % 2 == 0) cout << 1 << ' ';
                else cout << i / 2 + 2 << ' ';
            }
        }
    }
    else if (segl == 2 * n - 1) cout << n << ' ';
    else if (segl == 2 * n) cout << 1 << ' ';
    else if (segl % 2 == 1) cout << n << ' ';
    else{
        ForE(i, 1, a[segl]){
            if (l <= i + b[segl - 1]){
                if (i % 2 == 1) cout << segl / 2 << ' ';
                else cout << segl / 2 + i / 2 << ' ';
            }
        }
    }
    For(j, segl + 1, segr){
        if (j == 1) cout << 1 << ' ';
        else if (j == 2){
            ForE(i, 1, a[j]){
                if (i % 2 == 0) cout << 1 << ' ';
                else cout << i / 2 + 2 << ' ';
            }
        }
        else if (j == 2 * n - 1) cout << n << ' ';
        else if (j == 2 * n) cout << 1 << ' ';
        else if (j % 2 == 1) cout << n << ' ';
        else{
            ForE(i, 1, a[j]){
                if (i % 2 == 1) cout << j / 2 << ' ';
                else cout << j / 2 + i / 2 << ' ';
            }
        }
    }
    if (segr == 1) cout << 1 << ' ';
    else if (segr == 2){
        ForE(i, 1, a[segr]){
            if (i + b[segr - 1] <= r){
                if (i % 2 == 0) cout << 1 << ' ';
                else cout << i / 2 + 2 << ' ';
            }
        }
    }
    else if (segr == 2 * n - 1) cout << n << ' ';
    else if (segr == 2 * n) cout << 1 << ' ';
    else if (segr % 2 == 1) cout << n << ' ';
    else{
        ForE(i, 1, a[segr]){
            if (i + b[segr - 1] <= r){
                if (i % 2 == 1) cout << segr / 2 << ' ';
                else cout << segr / 2 + i / 2 << ' ';
            }
        }
    }
    cout << endl;
}
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/