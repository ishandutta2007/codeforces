#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <set>
#include <map>

using namespace std;

const int MAX = 5001;

int n, m, k;
pair<int, int> str[MAX], stb[MAX];

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        str[i] = make_pair(0, -1);
    for (int j = 0; j < m; j++)
        stb[j] = make_pair(0, -1);
    for (int i = 0; i < k; i++)
    {
        int f, r, a;
        cin >> f >> r >> a;
        r--;
        if (f == 1)
            str[r] = make_pair(a, i);
        else
            stb[r] = make_pair(a, i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (str[i].second > stb[j].second)
                cout << str[i].first;
            else
                cout << stb[j].first;
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}