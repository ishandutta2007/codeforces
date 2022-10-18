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
template <typename T, typename S>
void DBG(pair<T, S> p){if(debug)cout<<p.first<<" "<<p.second<<endl;}
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;

    vector<int> factors(1e7+3, 0);
    int p = 2;
    while (p < 1e7+3)
    {
        while (p < 1e7+3 && factors[p])
            p++;
        if (p < 1e7+3)
        {
            int q = p;
            while (q < 1e7+3)
            {
                factors[q] = p;
                q += p;
            }
        }
    }

    vector<int> c(1e7+3, 0);
    FOR(i, n)
    {
        int t;
        cin >> t;

        while (t > 1)
        {
            int factor = factors[t];
            while (t%factor==0)
                t /= factor;
            c[factor]++;
        }
    }

    vector<lint> psum(1e7+3, 0);
    FORR(i, 1, 1e7+3)
    {
        psum[i] = psum[i-1] + c[i];
    }

    int m;
    cin >> m;
    FOR(i, m)
    {
        lint l, r;
        cin >> l >> r;
        if (r > 1e7+1)
            r = 1e7+2;
        if (l > 1e7+1)
            l = 1e7+2;
        cout << psum[r] - psum[l-1] << endl;
    }
}