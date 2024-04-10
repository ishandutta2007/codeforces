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

map<int, int> M;

int main()
{
    int n;
    cin >> n;
    vi v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        sum += v[i];
        if (i < n - 1)
            M[sum]++;
    }
    if (sum % 3)
    {
        printf("0\n");
        return 0;
    }
    int64 res = 0;
    sum /= 3;
    int t = 0;
    for (int i = 0; i < n - 1; i++)
    {
        t += v[i];
        M[t]--;
        if (t == sum)
        {
            int x = t + sum;
            res += M[x];
        }
    }
    cout << res << "\n";
    return 0;
}