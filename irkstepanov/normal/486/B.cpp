#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 100500;
const int inf = 1000000000;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, m;
    int a[120][120], b[120][120];

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        cin >> b[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        a[i][j] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        if (!b[i][j])
    {
        for (int g = 0; g < m; g++)
            a[i][g] = 0;
        for (int g = 0; g < n; g++)
            a[g][j] = 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        if (b[i][j])
    {
        bool ok = false;
        for (int g = 0; g < m; g++)
            if (a[i][g]) ok = true;
        for (int g = 0; g < n; g++)
            if (a[g][j]) ok = true;
        if (!ok) {cout << "NO\n"; return 0;}
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

}