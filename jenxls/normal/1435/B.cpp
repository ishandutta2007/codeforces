#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 500 + 10;
int T;

int n, m, a[N][N], b[N][N], to[N * N];
bool mark[N * N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> n >> m;

        for (int i = 0; i <= n * m; i++)
            mark[i] = to[i] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

            mark[a[i][0]] = 1;
            to[a[i][0]] = i;
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> b[i][j];

        for (int k = 0; k < m; k++)
            if (mark[b[k][0]]){
                for (int ii = 0; ii < n; ii++) {
                    int i = to[b[k][ii]];

                    for (int j = 0; j < m; j++) cout << a[i][j] << ' ';
                    cout << '\n';
                }

                break;
            }
    }
}