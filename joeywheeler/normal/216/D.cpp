#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

#define MAX_N 1010

using namespace std;

int n;
vector<int> v[MAX_N];
map<int,int> c[MAX_N];
vector<int> bridge[MAX_N];

int main() {
    //freopen("d.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int p;
            scanf("%d", &p);
            bridge[i].push_back(p);
            v[i].push_back(p);
            v[(i+1)%n].push_back(p);
        }
    }
    for (int i = 0; i < n; i++) {
        sort(v[i].begin(), v[i].end());
        sort(bridge[i].begin(), bridge[i].end());
        for (int j = 0; j < v[i].size(); j++) {
            c[i][v[i][j]] = j;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bridge[i].size()-1; j++) {
            int l = c[i][bridge[i][j+1]] - c[i][bridge[i][j]];
            int r = c[(i+1)%n][bridge[i][j+1]] - c[(i+1)%n][bridge[i][j]];
            //if (i == 0) printf("%d %d\n", l, r);
            if (l != r) res++;
        }
    }
    printf("%d", res);
    //while (1);
}