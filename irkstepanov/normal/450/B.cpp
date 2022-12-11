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

const int inf = 1000000000;

typedef pair <int, int> pii;
typedef long long ll;

ll mod = 1000000007;

int main()
{

    ll x, y;
    cin >> x >> y;

    ll n;
    cin >> n;

    --n;
    n %= 6;

    ll m[6] = {x, y, y - x, -x, -y, x - y};
    ll t = m[n] % mod;
    if (t < 0) t += mod;

    cout << t;

}