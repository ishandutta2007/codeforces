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

const int maxn = 110;

bool a[maxn][maxn];

int u[maxn];

vi st;

int n, m;

void dfs0(int x) {
    u[x] = 1;
    for (int i = 0; i < n; ++i) if (a[x][i] && !u[i])
        dfs0(i);
}

int dfs(int x, int p = -1) {
    u[x] = 1;
    st.pb(x);

    for (int i = 0; i < n; ++i) if (a[x][i] && i != p) {
        if (u[i] == 2) continue;
        if (u[i] == 1) {
            int t = 0;
            while (st[t] != i) ++t;
            int s = sz(st) - t;
            a[st[t]][x] = false;
            a[x][st[t]] = false;
            while (t < sz(st) - 1) {
                a[st[t]][st[t + 1]] = false;
                a[st[t + 1]][st[t]] = false;
                ++t;            
            }
            return s;
        }
        int s = dfs(i, x);
        if (s > 0) return s;
    }

    u[x] = 2;
    st.pop_back();
    return 0;
}

int main()
{
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        a[x][y] = a[y][x] = true;
    }
    memset(u, 0, sizeof(u));
    dfs0(0);
    for (int i = 0; i < n; ++i)
        if (!u[i]) {
            printf("NO\n");
            return 0;
        }
    printf("%s\n", m == n ? "FHTAGN!" : "NO");
    /*
    memset(u, 0, sizeof(u));
    st.clear();
    int s = dfs(0);
    if (s < 3) {
        printf("NO\n");
        return 0;
    }
    memset(u, 0, sizeof(u));
    for (int i = 0; i < n; ++i) {
        st.clear();
        if (!u[i] && dfs(i)) {
            printf("NO\n");
            return 0;
        }
    }
    printf("FHTAGN!\n");*/
    return 0;
}