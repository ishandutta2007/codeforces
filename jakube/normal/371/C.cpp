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

    string s;
    vector<int> n(3), p(3);
    lint r;

    cin >> s;
    FOR(i, 3) cin >> n[i];
    FOR(i, 3) cin >> p[i];
    cin >> r;

    lint result = 0;
    vector<int> c(3, 0);
    for(char ch : s) c[ch == 'B' ? 0 : (ch == 'S' ? 1 : 2)]++;

    FOR(i, 3)
        if (c[i] == 0)
            n[i] = 0;

    while (accumulate(ALL(n), 0) && r >= 0)
    {
        FOR(i, 3)
            n[i] -= c[i];
        FOR(i, 3)
        {
            if (n[i] < 0) {
                r += n[i] * p[i];
                n[i] = 0;
            }
        }

        if (r >= 0)
        {
            result++;
        }
    }

    int total = 0;
    FOR(i, 3)
        total += c[i]*p[i];

    if (r >= 0)
        result += r / total;
    cout << result;
}