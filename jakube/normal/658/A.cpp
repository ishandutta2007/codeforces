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

    int n, c;
    cin >> n >> c;

    vector<int> p(n), t(n);
    FOR(i, n) cin >> p[i];
    FOR(i, n) cin >> t[i];

    lint limak = 0;
    lint time = 0;
    FOR(i, n)
    {
        time += t[i];
        limak += max(0LL, p[i] - time * c);
    }

    time = 0;
    lint radewoosh = 0;
    FOR(i, n)
    {
        time += t[n-i-1];
        radewoosh += max(0LL, p[n-i-1] - time * c);
    }

    if (limak > radewoosh)
        cout << "Limak";
    else if (limak < radewoosh)
        cout << "Radewoosh";
    else
        cout << "Tie";

}