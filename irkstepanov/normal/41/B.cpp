#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <queue>
#include <cstdlib>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef long long ll;

int main()
{

    int n, b;
    cin >> n >> b;

    vector <int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = b;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
    {
        int k = b / a[i];
        ans = max(ans, b - k * (a[i] - a[j]));
    }

    cout << ans;

}