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

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int main()
{
    string s;
    cin >> s;
    int res = 0;
    for (int l = 1; l <= sz(s); l++)
    {
        vector<string> v;
        for (int i = 0; i + l - 1 < sz(s); i++)
            v.pb(s.substr(i, l));
        sort(all(v));
        for (int i = 0; i < sz(v) - 1; i++)
            if (v[i] == v[i + 1])
            {
                res = l;
                break;
            }
    }
    cout << res << "\n";
    return 0;
}