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


int b[100];

bool u[1010];

int main()
{
    int n;
    cin >> n;
    int cur = 1;
    for (int i = 0; i < n; ++i)
    {
        b[i] = cur;
        while (1)
        {
            bool ok = true;
            for (int j = 0; j < i; ++j)
                if (u[b[i] + b[j]])
                {
                    ok = false;
                    break;
                }
            if (ok) break;
            ++b[i];
        }
        for (int j = 0; j < i; ++j)
            u[b[i] + b[j]] = true;
        cur = b[i] + 1;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%d ", i == j ? 0 : (b[i] + b[j]));
        printf("\n");
    }
    return 0;
}