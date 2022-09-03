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

typedef long long ll;

const int MAX_N = 200001;

int n, c1[MAX_N], c2[MAX_N];
vector<int> a, b;

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x != 0)
            a.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x != 0)
            b.push_back(x);
    }
    for (int i = 0; i < n - 1; i++)
        c1[a[i]] = i;
    for (int i = 0; i < n - 1; i++)
        c2[b[i]] = i;
    int t = c2[1] - c1[1];
    bool fl = true;
    for (int i = 1; i < n; i++)
        if ((c1[i] + t + 2 * n - 2) % (n - 1) != c2[i]){
            fl = false;
            //cerr << i << endl;
        }
    cout << (fl ? "YES" : "NO");
    return 0;
}