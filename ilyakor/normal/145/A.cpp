#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
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
    string sa, sb;
    cin >> sa >> sb;
    int x = 0, y = 0;
    for (int i = 0; i < sz(sa); ++i) {
        if (sa[i] != sb[i]) {
            if (sa[i] == '4') ++x;
            else ++y;
        }
    }
    cout << max(x, y) << "\n";
    return 0;
}