#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

int main()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int x = 0, y = 1;
    for (int i = 0; i < n; ++i)
    {
        int j = (i + 1) % n;
        if (abs(v[i] - v[j]) < abs(v[x] - v[y]))
            x = i, y = j;
    }
    printf("%d %d\n", x + 1, y + 1);
    return 0;
}