#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

int main()
{
    int n;
    int64 d;
    cin >> n >> d;
    vector<int64> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int64 res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i + 1] > v[i]) continue;
        int64 delta = v[i] - v[i + 1] + 1;
        int64 cur = delta / d;
        if (delta % d) cur++;
        res += cur;
        v[i + 1] += d * cur;
    }
    cout << res << "\n";
    return 0;
}