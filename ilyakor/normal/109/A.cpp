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

bool cmp(ii p, ii q) {
    if (p.first == -1) return false;
    if (q.first == -1) return true;
    if (p.first + p.second != q.first + q.second)
        return p.first + p.second < q.first + q.second;
    return p.first > q.first;
}

int main()
{
    int n;
    cin >> n;
    ii res(-1, -1);
    for (int i = 0; 7 * i <= n; ++i)
        if ((n - 7 * i) % 4 == 0) {
            int k = (n - 7 * i) / 4;
            if (cmp(ii(k, i), res))
                res = ii(k, i);
        }
    if (res.first == -1) printf("-1\n");
    else {
        for (int i = 0; i < res.first; ++i)
            printf("4");
        for (int i = 0; i < res.second; ++i)
            printf("7");
        printf("\n");
    }
    return 0;
}