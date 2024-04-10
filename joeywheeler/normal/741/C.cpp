#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
vector<int> u[200005];
int c[200005];

void go(int i) {
    for (int j : u[i]) if (c[j] == 0) {
        c[j] = 3-c[i]; go(j);
    }
}

vector<pair<int,int> > v;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        u[a].push_back(b);
        u[b].push_back(a);
        v.emplace_back(a,b);
    }
    FO(i,0,2*n) {
        u[i].push_back(i^1);
    }
    FO(i,0,2*n) if (c[i] == 0) c[i] = 1, go(i);
    FO(i,0,n) printf("%d %d\n", c[v[i].first], c[v[i].second]);
}