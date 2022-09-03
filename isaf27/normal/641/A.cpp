#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
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

const int MAX_N = 100001;

bool used[MAX_N];
int n, a[MAX_N];
string s;

void dfs(int p)
{
    used[p] = true;
    int go;
    if (s[p] == '<')
        go = p - a[p];
    else
        go = p + a[p];
    if (go < 0 || go >= n)
    {
        cout << "FINITE";
        exit(0);
    }
    if (used[go])
    {
        cout << "INFINITE";
        exit(0);
    }
    dfs(go);
}

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0);
    return 0;
}