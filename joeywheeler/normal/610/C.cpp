#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<vector<int> > solve(int n) {
    if (n == 0) {
        return {{1}};
    } else {
        vector<vector<int> > v = solve(n-1);
        FO(i,0,sz(v)) {
            int k = sz(v[i]);
            FO(j,0,k) v[i].push_back(v[i][j]);
        }
        int m = sz(v);
        FO(i,0,m) {
            v.push_back(v[i]);
            int k = sz(v[i]);
            FO(j,k/2,k) v.back()[j] = -v.back()[j];
        }
        return v;
    }
}

int main() {
    int n; scanf("%d", &n);
    auto v = solve(n);
    for (auto u : v) {
        for (int x : u) {
            if (x == 1) printf("+");
            else printf("*");
        }
        printf("\n");
    }
}