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

map<int, int> ma;
vector<vector<int>> wins, looses;


int f(int cur)
{
    if (ma.count(cur))
    {
        return ma[cur];
    }
    else
    {
        int mx = 0;
        for (auto t : looses[cur])
        {
            mx = max(mx, f(t));
        }
        mx++;
        ma[cur] = mx;
        return mx;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> battles(m);
    FOR(i, n) {
        wins.push_back(vector<int>());
        looses.push_back(vector<int>());
    }

    FOR(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        wins[u].push_back(v);
        looses[v].push_back(u);
        battles[i] = make_pair(u, v);
    }

    FOR(i, n) {
        f(i);
    }

    vector<pair<int, int>> v;
    for (auto p : ma)
    {
        v.push_back(make_pair(p.second, p.first));
    }

    sort(ALL(v));

    FOR(i, n-1)
    {
        if (v[i].first == v[i+1].first)
        {
            cout << -1;
            return 0;
        }
    }

    vector<int> order;
    FOR(i, n)
        order.push_back(v[i].second);

    set<pair<int,int>> se;
    FOR(i, n-1)
    {
        se.insert(make_pair(order[i], order[i+1]));
    }

    //DBG(order);

    FOR(i, m)
    {
        if (se.count(battles[i]))
        {
            se.erase(battles[i]);
            if (se.size() == 0)
            {
                cout << i+1;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}