#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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

    int n;
    int m[100500];
    for (int i = 1; i < 100500; i++)
        m[i] = -1;
    cin >> n;

    while (n--)
    {
        int x, k;
        cin >> x >> k;
        if (x > m[k] + 1) {cout << "NO\n"; return 0;}
        m[k] = max(m[k], x);
    }

    cout << "YES\n";

}