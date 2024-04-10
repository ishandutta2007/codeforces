#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define pb push_back

using namespace std;

typedef long long ll;
typedef vector <vector <ll> > matrix;
ll mod;

int main()
{

    int n;
    char m[120][120];

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        cin >> m[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
    {
        int ok = 1;
        for (int y = 0; y < n; y++)
            if (m[i][y] != 'E') ok = 0;
        for (int x = 0; x < n; x++)
            if (m[x][j] != 'E') ok = 0;
        if (ok) {cout << "-1"; return 0;}
    }

    int str = 1;
    for (int i = 0; i < n; i++)
    {
        int ok = 1;
        for (int j = 0; j < n; j++)
            if (m[i][j] != 'E') ok = 0;
        if (ok) str = 0;
    }

    if (str)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (m[i][j] != 'E')
            {
                cout << i + 1 << " " << j + 1 << "\n";
                break;
            }
        }
    }

    else
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
                if (m[i][j] != 'E')
            {
                cout << i + 1 << " " << j + 1 << "\n";
                break;
            }
        }
    }

}