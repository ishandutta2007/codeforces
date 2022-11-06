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

const int N = 50 + 20;

int T;

int n, a[N];

int cnt;
bool mark[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        cnt = 0;
        for (int i = 0; i < N; i++) mark[i] = false;

        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) {
                int val = a[i] - a[j];

                if (!mark[val]) {
                    cnt++;
                    mark[val] = true;
                }
            }

        cout << cnt << '\n';
    }
}