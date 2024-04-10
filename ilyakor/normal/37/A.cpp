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
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++m[x];
    }
    int r1 = 0;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
        r1 = max(r1, it->second);
    cout << r1 << " " << sz(m) << "\n";
    return 0;
}