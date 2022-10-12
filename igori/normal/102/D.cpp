#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
const long long mod = 1e9 + 7;
long long n, m;
long long a[500000], b[500000];
map<int, int> all;
map<int, int> crd;
long long dp[500000];
long long fenw[500000];
int N;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void add(int pos, int val)
{
    for (int i = pos; i <= N; i |= (i + 1))
    {
        fenw[i] += val;
        if (fenw[i] >= mod) fenw[i] %= mod;
    }
}

long long get(int pos)
{
    long long res = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
    {
        res += fenw[i];
    }
    return res;
}

long long summ(int l, int r)
{
    return (get(r) - get(l - 1) + mod) % mod;
}

int main()
{
   cin >> n >> m;
   all[0] = 1;
   vector<pair<int, int>> c;
   for (int i = 0; i < m; i++)
   {
       int s, t;
       cin >> s >> t;
       all[s] = 1;
       all[t] = 1;
       c.push_back({s, t});
   }
   sort(c.begin(), c.end(), comp);
   for (int i = 0; i < m; i++)
   {
       a[i] = c[i].first;
       b[i] = c[i].second;
   }
   all[n] = 0;
   int id = 0;
   for (auto it : all)
   {
       crd[it.first] = id;
       id++;
   }
   N = id;
   dp[0] = 1;
   add(0, 1);
   for (int i = 0; i < m; i++)
   {
       int t = crd[b[i]];
       dp[t] = (dp[t] + summ(crd[a[i]], t - 1)) % mod;
       add(t, summ(crd[a[i]], t - 1));
   }
   //for (int i = 0; i < id; i++)
   //{
   //    cout << dp[i] << endl;
   //}
   //cout << endl;
   cout << dp[id - 1];
}