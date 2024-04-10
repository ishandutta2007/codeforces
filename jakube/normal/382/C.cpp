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
    vector<int> v(n);
    FOR(i, n) cin >> v[i];
    sort(ALL(v));

    if (v.size() == 1)
    {
        cout << -1;
        return 0;
    }

    if (v.size() == 2)
    {
        int d = v[1] - v[0];
        if (d == 0)
        {
            cout << 1 << endl;
            cout << v[0];
        }
        else
        {
            cout << 2 + (d%2==0) << endl;
            cout << v[0] - d << " ";
            if (d%2 == 0)
                cout << (v[1] + v[0])/2 << " ";
            cout << v[1] + d << endl;
        }
        return 0;
    }

    map<int, int> s;
    bool b = false;
    FOR(i, n-1)
    {
        int d = v[i+1]-v[i];
        if (s.count(d))
        {
            if (b && s[d] == 1)
            {
                cout << 0;
                return 0;
            }
            b = true;
            s[d]++;
        }
        else
        {
            if (s.size() == 2) {
                cout << 0;
                return 0;
            }
            s[d] = 1;
        }
    }

    set<int> results;
    if (s.size() == 1)
    {
        results.insert(v[0] - (v[1] - v[0]));
        results.insert(v[n-1] + (v[1] - v[0]));
    }
    else
    {
        vector<int> result;
        int sum = 0;
        for (auto p : s)
            sum += p.first;
        for (auto p : s)
        {
            if (p.second == 1)
            {
                int d = p.first;
                FOR(i, n-1)
                {
                    if (v[i+1] - v[i] == d)
                    {
                        if (d == (sum - d)*2)
                        {
                            results.insert(v[i] + (sum - d));
                        }
                    }
                }
            }
        }

    }

    cout << results.size() << endl;
    for (auto d : results)
        cout << d << " ";
}