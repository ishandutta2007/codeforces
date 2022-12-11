#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define pb push_back

#define x first
#define y second

using namespace std;

typedef long double ld;
const ld eps = 0.0000001;
typedef pair <int, int> pii;

bool comp (pii a, pii b)
{
    if (a.x > b.x) return true;
    if (a.x == b.x && a.y < b.y) return true;
    return false;
}

int main()
{

    int n, k;
    cin >> n >> k;

    vector <pii> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].x >> v[i].y;

    sort(v.begin(), v.end(), comp);

    int ans = 0;
    --k;
    for (int i = 0; i < n; i++)
        if (v[i].x == v[k].x && v[i].y == v[k].y) ++ans;

    cout << ans;

}