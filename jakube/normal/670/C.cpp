#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);
const long long int MOD = 1e9 + 7;

typedef long long int lint;
typedef long double ld;
lint powmod(lint a,lint b, lint mod) {lint res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int debug = 1;
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n;
    vector<int> a(n);
    FOR(i, n) cin >> a[i];

    cin >> m;
    vector<int> b(m), c(m);
    FOR(i, m) cin >> b[i];
    FOR(i, m) cin >> c[i];

    map<int, int> lang;
    for (const auto& l : a)
    {
        if (!lang.count(l))
            lang[l] = 0;
        lang[l] += 1;
    }

    int b_i = 0;
    int b_a = -1;
    int b_b = -1;

    FOR(i, m)
    {
        int r = 0;
        int s = 0;
        if (lang.count(b[i]))
            r = lang[b[i]];
        if (lang.count(c[i]))
            s = lang[c[i]];

        if (r > b_a || (r == b_a && s > b_b))
        {
            b_i = i;
            b_a = r;
            b_b = s;
        }
    }
    
    cout << b_i + 1 << endl;
}