#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int n, d, h;
vector<pair<int, int> > ans;

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    cin >> n >> d >> h;
    if (d == 1 && n != 2)
    {
        cout << -1;
        return 0;
    }
    if (d > 2 * h)
    {
        cout << -1;
        return 0;
    }
    if (d == h)
    {
        for (int i = 0; i < h; i++)
            cout << i + 1 << " " << i + 2 << endl;
        for (int i = h + 1; i < n; i++)
            cout << 2 << " " << i + 1 << endl;
        return 0;
    }
    int v1 = d - h;
    for (int i = 0; i < h; i++)
        ans.push_back(make_pair(i, i + 1));
    for (int i = 0; i < v1 - 1; i++)
        ans.push_back(make_pair(i + h + 1, i + 2 + h));
    ans.push_back(make_pair(0, h + 1));
    for (int i = d + 1; i < n; i++)
        ans.push_back(make_pair(0, i));
    for (pair<int, int> p : ans)
        cout << p.first + 1 << " " << p.second + 1 << endl;
    return 0;
}