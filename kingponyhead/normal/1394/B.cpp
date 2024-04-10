// M
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9, Mod = 1e9 + 9;
int n, m, k, Cnt, Pw[N], H[11][11];
vector < int > Adj[N], V[11];
int SM = 0, targ;
void Solve(int lvl)
{
        if (lvl == k + 1)
        {
                if (SM == targ)
                        Cnt ++;
                return ;
        }
        for (int j = 0; j < lvl; j ++)
        {
                SM = (SM + H[lvl][j]) % Mod;
                Solve(lvl + 1);
                SM = (SM - H[lvl][j] + Mod) % Mod;
        }
}
int main()
{
        for (int i = Pw[0] = 1; i < N; i ++)
                Pw[i] = Pw[i - 1] * 718301903LL % Mod;
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        cin >> n >> m >> k;
        vector < tuple < int , int , int > > E;
        for (int i = 1; i <= n; i ++)
                targ = (targ + Pw[i]) % Mod;
        for (int i = 0; i < m; i ++)
        {
                int v, u, w;
                cin >> v >> u >> w;
                E.push_back({w, v, u});
        }
        sort(E.begin(), E.end());
        for (auto X : E)
        {
                int w, v, u;
                tie(w, v, u) = X;
                Adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i ++)
                V[(int)Adj[i].size()].push_back(i);
        for (int i = 1; i <= k; i ++)
        {
                for (int j = 0; j < i; j ++)
                {
                        int hsh = 0;
                        for (int v : V[i])
                                hsh = (hsh + Pw[Adj[v][j]]) % Mod;
                        H[i][j] = hsh;
                }
        }
        Solve(1);
        printf("%d\n", Cnt);
        return 0;
}