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

const char fruits[100][100] = {"Carrots", "Kiwis", "Grapes"};

int main()
{
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<ii> v(k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &v[i].first, &v[i].second);
        --v[i].first, --v[i].second;
    }
    sort(all(v));
    for (int i = 0; i < t; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        int ind = lower_bound(all(v), ii(x, y)) - v.begin();
        if (v[ind] == ii(x, y)) {
            printf("Waste\n");
            continue;
        }
        int cnt = ((x * m + y - ind) % 3 + 3) % 3;
        printf("%s\n", fruits[cnt]);
    }

    return 0;
}