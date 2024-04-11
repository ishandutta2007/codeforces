#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> r;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        r.push_back(make_pair(x, i + 1));
    }
    sort(r.rbegin(), r.rend());
    cout << r[k - 1].first << endl;
    for (int i = 0; i < k; ++i)
    {
        cout << r[i].second << ' ';
    }
    return 0;
}