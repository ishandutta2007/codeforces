#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>

using namespace std;

typedef long long int64;
typedef long long LL;
typedef long double real;
typedef long double LD;

#define mp make_pair
#define PII pair<int, int>
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const double PI = acos(0.) * 2;
const int lim = 1000000000;
const int inf = ~0U >> 1;

template<class T> T abs(T x){return x < 0 ? -x : x;}

int f[105][2][2];
int x[105], y[105];

void up(int &a, int b)
{
    if (b < a) a = b;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 0; i <= n; ++i)
        for (int p = 0; p < 2; ++p)
            for (int q = 0; q < 2; ++q)
                f[i][p][q] = lim;
    f[n][0][0] = 0;
    for (int i = n - 1; i >= 0; --i)
        for (int p = 0; p < 2; ++p)
            for (int q = 0; q < 2; ++q)
            {
                up(f[i][(p + x[i]) & 1][(q + y[i]) & 1], f[i + 1][p][q]);
                up(f[i][(p + y[i]) & 1][(q + x[i]) & 1], f[i + 1][p][q] + 1);
            }
    if (f[0][0][0] == lim) f[0][0][0] = -1;
    cout << f[0][0][0] << endl;
    return 0;
}