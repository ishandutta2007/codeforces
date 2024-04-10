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

    vector<pair<int, int>> v(n);
    FOR(i, n) cin >> v[i].first >> v[i].second;

    lint result = 0;
    FOR(i, 2)
    {
        map<int, int> m;
        FOR(j, n)
        {
            int idx = 0;
            if (i)
                idx = v[j].first;
            else
                idx = v[j].second;

            if (!m.count(idx))
                m[idx] = 1;
            else
                m[idx] += 1;
        }

        for (auto it = m.begin(); it != m.end(); ++it)
        {
            lint count = it->second;
            result += (count * (count-1))/2;
            //DBG(vector<lint>{it->first, count, (count * (count-1))/2});
        }
    }

    map<pair<int, int>, int> m;
    FOR(i, n)
    {
        auto p = v[i];
        if (m.count(p))
            m[p]++;
        else
            m[p] = 1;
    }

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        lint count = it->second;
        result -= (count * (count-1)) / 2;
    }

    cout << result;
}