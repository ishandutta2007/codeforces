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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1, vector<int>());
    v[0] = vector<int>(1<<n);

    FOR(i, 1 << n) cin >> v[0][i];

    FORR(j, 1, n+1)
    {

        for (int i = 0; i < v[j-1].size(); i += 2)
        {
            int m = 1 << j;
            if (j%2)
                v[j].push_back(v[j-1][i] | v[j-1][i+1]);
            else
                v[j].push_back(v[j-1][i] ^ v[j-1][i+1]);
        }
    }

    FOR(i, m)
    {
        int p, b;
        cin >> p >> b;

        p--;
        v[0][p] = b;

        FORR(j, 1, n+1)
        {
            p /= 2;
            if (j%2)
                v[j][p] = v[j-1][2*p] | v[j-1][2*p+1];
            else
                v[j][p] = v[j-1][2*p] ^ v[j-1][2*p+1];
        }

        DBG(v[n][0]);
    }
}