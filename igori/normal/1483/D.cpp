#include <iostream>

using namespace std;

const int N = 600;

int E[N][N];
int W[N][N];
int S[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            S[i][j] = 1e9 + 2;
        }
        S[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int f, t, w;
        cin >> f >> t >> w;
        f--, t--;
        E[f][t] = w;
        E[t][f] = w;
        S[f][t] = w;
        S[t][f] = w;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int f, t, w;
        cin >> f >> t >> w;
        f--, t--;
        W[f][t] = w;
        W[t][f] = w;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                S[i][j] = min(S[i][j], S[i][k] + S[k][j]);
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                W[i][j] = max(W[i][j], W[i][k] - S[j][k]);
                W[i][j] = max(W[i][j], W[k][j] - S[i][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += (E[i][j] > 0 && W[i][j] >= E[i][j]);
        }
    }
    cout << ans / 2;
}