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
    vector<lint> diag(2*n-1, 0), anti(2*n-1, 0);
    vector<vector<int>> v(n, vector<int>(n));


    FOR(i, n)
    {
        FOR(j, n)
        {
            cin >> v[i][j];
            diag[j-i+(n-1)] += v[i][j];
            anti[i+j] += v[i][j];
        }
    }

    vector<lint> best(2, 0);
    vector<pair<int, int>> p(2);

    multimap<lint, pair<int,int>> mm, mm2;
    FOR(i, n)
    {
        FOR(j, n)
        {
            lint value = (diag[j-i+(n-1)] + anti[i+j] - v[i][j]);
            if (value >= best[(i+j)%2])
            {
                best[(i+j)%2] = value;
                p[(i+j)%2] = make_pair(i+1, j+1);
            }
        }
    }

    DBG(accumulate(ALL(best), 0LL));
    DBG(vector<int>{p[0].first, p[0].second, p[1].first, p[1].second});
}