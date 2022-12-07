#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <stack>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acosl(-1.);
using namespace std;

const int N = 100111;
bool used[N];

vector<int> g[N];

vector< vector<int> > cycles, lines;
set< pair<int, int> > got;

void add(int a, int b) {
    if (a > b) swap(a, b);
    got.insert(make_pair(a, b));
}

bool have(int a, int b) {
    if (a > b) swap(a, b);
    return got.find(make_pair(a, b)) != got.end();
}

int need;
vector< pair<int, int> > ans;
vector< pair<int, int> > pool;
int D[N];
void rec(int l, int last) {
   if (l == need) {
       for (int i = 0; i < ans.size(); ++i) printf("%d %d\n", ans[i].first, ans[i].second);
       exit(0);
   }

   for (int i = last; i < pool.size(); ++i) {
       if (D[pool[i].first] < 2 && D[pool[i].second] < 2) {
            D[pool[i].first]++;
            D[pool[i].second]++;
            ans.push_back(pool[i]);
            rec(l + 1, i + 1);
            D[pool[i].first]--;
            D[pool[i].second]--;
            ans.pop_back();
       }
   }
}

int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    //freopen("out", "w", stdout);

    srand(1993);

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);

        g[a].push_back(b);
        g[b].push_back(a);

        add(a, b);
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            vector<int> a;

            stack<int> q;
            used[i] = true; 
            q.push(i);
            int sum = 0;
            while (!q.empty()) {
                int x = q.top(); q.pop();
                sum += g[x].size();
                a.push_back(x);
                for (int j = 0; j < g[x].size(); ++j) {
                    if (!used[ g[x][j] ]) {
                        used[ g[x][j] ] = true;
                        q.push(g[x][j]);
                    }
                }
            }

            if (sum == a.size() * 2) {
                cycles.push_back(a);
            } else {
                for (int j = 0; j < a.size(); ++j)
                    if (g[ a[j] ].size() == 1) {
                        swap(a[0], a[j]);
                        break;
                    }
                for (int j = 1; j < a.size(); ++j)
                    if (g[ a[j] ].size() == 1) {
                        swap(a[j], a[ a.size() - 1 ]);
                        break;
                    }
                lines.push_back(a);
            }

#ifdef DEBUG
            if (sum == a.size() * 2) puts("cycle");
            else puts("line");
            for (int i = 0; i < a.size(); ++i) {
                cerr << a[i] << " ";
            }
            cerr << endl;
#endif
        }
    }

    int nlines = n - m;
    int ncycles = m;

    if (ncycles >= 5) {
        vector<int> a;
        for (int i = 1; i <= n; ++i) a.push_back(i);

        bool cool;
        do {
           cool = true;
           random_shuffle(a.begin(), a.end());
           for (int i = 0; i < m; ++i)
               if (have(a[i], a[(i + 1) % m])) {
                    cool = false;
                    break;
               }
        } while (!cool);
        for (int i = 0; i < m; ++i) printf("%d %d\n", a[i], a[ (i + 1) % m ]);
        return 0;
    } else {
        need = m;

        int clim = min(n, 8);
            
        for (int i = 1; i <= clim; ++i)
            for (int j = i + 1; j <= clim; ++j)
                if (!have(i, j)) {
                    pool.push_back(make_pair(i, j));
                }

        rec(0, 0);
    }
    puts("-1");

    return 0;
}