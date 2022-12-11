#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef unsigned long long ll;
typedef pair <int, int> pii;
typedef long double ld;

const int maxn = 60;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    char m[maxn][maxn];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        cin >> m[i][j];

    char step[2 * maxn][2 * maxn];
    char use[2 * maxn][2 * maxn];

    for (int i = 0; i < 2 * maxn; i++)
        for (int j = 0; j < 2 * maxn; j++)
        step[i][j] = '.', use[i][j] = false;

    step[maxn][maxn] = '-';

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        if (m[i][j] == 'o')
    {
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
            if (m[x][y] == '.') step[x - i + maxn][y - j + maxn] = '-';
    }

    char check[maxn][maxn];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        if (m[i][j] == 'o') check[i][j] = 'o';
        else check[i][j] = '.';

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        if (m[i][j] == 'o')
    {
        for (int x = 0; x < 2 * maxn; x++)
            for (int y = 0; y < 2 * maxn; y++)
            if (step[x][y] == '.')
        {
            int tox = x + i - maxn, toy = y + j - maxn;
            if (tox >= 0 && tox < n && toy >= 0 && toy < n && m[tox][toy] != 'o' && check[tox][toy] != 'x')
                {check[tox][toy] = 'x'; use[x][y] = true;}
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        if (m[i][j] != check[i][j]) {cout << "NO\n"; return 0;}

    cout << "YES\n";

    for (int i = maxn - n + 1; i <= maxn + n - 1; i++)
    {
        for (int j = maxn - n + 1; j <= maxn + n - 1; j++)
        {
            if (i == maxn && j == maxn) cout << 'o';
            else if (step[i][j] == '-' || !use[i][j]) cout << '.';
            else cout << 'x';
        }
        cout << "\n";
    }

}