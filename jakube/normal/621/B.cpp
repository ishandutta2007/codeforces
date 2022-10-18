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

lint f(map<int,int> m)
{
    lint result = 0;

    for (auto& kv : m)
    {
        lint n = kv.second;
        result += n*(n-1)/2;
    }

    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;

    map<int, int> diag1, diag2;

    FOR(i, n)
    {
        int x, y;
        cin >> x >> y;

        int a = x - y;
        if (diag1.count(a))
            diag1[a]++;
        else
            diag1[a] = 1;

        int b = x + y;
        if (diag2.count(b))
            diag2[b]++;
        else
            diag2[b] = 1;
    }

    cout << f(diag1) + f(diag2) << endl;
}