#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;

vector<int> v[400005];

int main() {
    scanf("%d %d", &n, &k);
    FO(i,0,k) {
        int m; scanf("%d", &m);
        v[i].resize(m);
        for (int &x : v[i]) scanf("%d", &x);
    }
    int res = 0;
    FO(i,0,k) {
        int li = sz(v[i]);
        for (int j = sz(v[i])-2; j >= 0; j--) {
            if (v[i][j+1]-v[i][j] > 1) {
                li = j+1;
            }
        }
        while (sz(v[i]) > li) {
            v[k].push_back(v[i].back());
            v[i].pop_back();
            res++;
            k++;
        }
    }
    FO(i,0,k) if (v[i][0] != 1) res += 2 * sz(v[i])-1;
    printf("%d\n", res);
}