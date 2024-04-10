#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>

const int MAXN = 3e5 + 2;

using namespace std;

typedef long long ll;
#define sz size()
#define pb push_back
int n, m;
int a[MAXN], b[MAXN], c[MAXN];
map<int, int> mm;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mm[a[i]]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    cin >> b[i];
    for (int i = 0; i < m; i++)
    cin >> c[i];
    int a1 = 0, a2 = 0, id = 1;
    for (int i = 0; i < m; i++)
    {
        int vd = mm[b[i]];
        int cd = mm[c[i]];
        if (vd > a1)
        {
            a1 = vd;
            a2 = cd;
            id = i + 1;
        }
        if (vd == a1 && cd > a2)
        {
            a2 = cd;
            id = i + 1;
        }
    }
    cout << id << endl;
}