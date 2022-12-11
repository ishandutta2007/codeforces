#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
ll mod = 1000000007;

int main()
{

    int n;
    ll x;

    cin >> n >> x;
    ll c[100500];

    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);

    ll t = 0;
    for (int i = 0; i < n; i++)
    {
        t += c[i] * x;
        x = max((ll) 1, x - 1);
    }

    cout << t;

}