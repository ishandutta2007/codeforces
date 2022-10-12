#include <bits/stdc++.h>
using namespace std;
 
long long n, k;
int nxt[500021];
int p[500021];
vector<int> pos[500021];

int pos_of_next_equal_to_x(int l, int r, int x)
{
    int L = -1, R = pos[x].size();
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        if (pos[x][M] >= l)
        {
            R = M;
        }
        else
        {
            L = M;
        }
    }
    if (R == pos[x].size() || pos[x][R] > r)
    {
        return -1;
    }
    return pos[x][R];
}

void slovo(int l, int r, int numl, int numr)
{
    if (r < l) return;
    //cout << l << " " << r << " " << numl << " " << numr << endl;
    int posi = pos_of_next_equal_to_x(l, r, r + 1);
    if (posi == -1)
    {
        p[r] = numr;
        slovo(l, r - 1, numl, numr - 1);
        return;
    }
    p[posi] = numr;
    //cout << posi << " " << numr << endl;
    numr--;
    int cnt = posi - l;
    slovo(l, posi - 1, numl, numl + cnt - 1);
    slovo(posi + 1, r, numl + cnt, numr);
}

int sparce[20][500021];
int H[500021];

int get(int l, int r)
{
    int len = r - l + 1;
    int h = H[len];
    return max(sparce[h][l], sparce[h][r - (1 << h) + 1]);
}

void solve()
{
    cin >> n;
    fill(p, p + n + 1, -1);
    for (int i = 1; i <= n; i++) cin >> nxt[i];
    for (int i = 1; i <= n + 1; i++)
    {
        pos[i].resize(0);
        pos[i].shrink_to_fit();
    }
    for (int i = 1; i <= n; i++) if (nxt[i] != -1) pos[nxt[i]].push_back(i);
    slovo(1, n, 1, n);
    //illegal
    //for (int i = 1; i <= n; i++) cout << p[i] << " ";
    //cout << "\n";
    //return;
    p[n + 1] = n + 1;
    int deg = n + 1;
    
    for (int i = 1; i <= n; i++)
    {
        sparce[0][i] = p[i];
    }
    
    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            sparce[j][i] = get(i, i + (1 << j) - 1);
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == -1)
        {
            cout << "-1\n";
            return;
        }
        if (nxt[i] != -1)
        {
            int x = get(i + 1, nxt[i] - 1);
            if (nxt[i] == i + 1)
                continue;
            if (x > p[i])
            {
                cout << "-1\n";
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << "\n";
}

signed main()
{
    H[1] = 0;
    H[2] = 0;
    H[3] = 1;
    for (int i = 4; i <= 500020; i++)
    {
        H[i] = H[i - 1];
        if (((i - 1) & (i - 2)) == 0) H[i]++;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}