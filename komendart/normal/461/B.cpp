#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef unsigned long long ll;

const ll MOD = (ll) 1e+9 + 7;

ll power(ll x, ll p)
{
    if (!p) return 1;
    if (p & 1) return x * power(x, p - 1) % MOD;
    ll tmp = power(x, p >> 1);
    return tmp * tmp % MOD;
}

vector< vector<int> > child;
vector<int> color;

pair<ll, ll> get_res(int vertice)
{
    if (color[vertice] == 1)
    {
        ll mul = 1;
        
        for (int i = 0; i < child[vertice].size(); i += 1)
        {
            pair<ll, ll> tmp = get_res(child[vertice][i]);
            mul = mul * ((tmp.first + tmp.second) % MOD) % MOD;
        }
        //cout << vertice << ' ' << 0 << ' ' << mul << endl;
        return make_pair(0, mul);
    }
    else
    {
        vector< pair<int, int> > saved;
        
        ll mul = 1;
        
        for (int i = 0; i < child[vertice].size(); i += 1)
        {
            pair<ll, ll> tmp = get_res(child[vertice][i]);
            mul = mul * ((tmp.first + tmp.second) % MOD) % MOD;
            saved.push_back(tmp);
        }
        
        ll res1 = 0;
        for (auto p: saved)
        {
            ll tmp = (p.first + p.second) % MOD;
            res1 = (res1 + mul * p.second % MOD * power(tmp, MOD - 2) % MOD) % MOD;
        }
        //cout << vertice << ' ' << mul << ' ' << res1 << endl;
        return make_pair(mul, res1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    child = vector< vector<int> >(n, vector<int>());
    color = vector<int>(n, 0);
    
    for (int i = 1; i <= n - 1; i += 1)
    {
        int p; cin >> p;
        child[p].push_back(i);
    }
    
    for (int i = 0; i < n; i += 1)
    {
        int c; cin >> c; color[i] = c;
    }
    
    cout << get_res(0).second << endl;
}