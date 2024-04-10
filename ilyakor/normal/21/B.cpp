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
    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    if (a1 == 0 && b1 == 0 && a2 == 0 && b2 == 0)
    {
        if (c1 == 0 && c2 == 0)
            printf("-1\n");
        else
            printf("0\n");
        return 0;
    }
    int det = a1 * b2 - a2 * b1;
    if (det != 0)
    {
        cout << "1\n";
    }
    else
    {
        int dx = a1 * c2 - a2 * c1;
        int dy = b1 * c2 - b2 * c1;
        if (dx == 0 && dy == 0)
            cout << "-1\n";
        else
            cout << "0\n";
    }
    return 0;
}