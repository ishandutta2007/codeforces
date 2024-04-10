#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
pair<int,int> e[100005];
vector<int> u[100005];
int ind[100005];

bool uniq(int m) {
    FO(i,0,n) {
        u[i].clear();
        ind[i] = 0;
    }
    FO(i,0,m) {
        u[e[i].first].emplace_back(e[i].second);
        ind[e[i].second]++;
    }
    queue<int> q;
    FO(i,0,n) if (ind[i] == 0) {
        q.push(i);
    }
    FO(t,0,n) {
        if (sz(q) > 1) return false;
        int f = q.front(); q.pop();
        for (int j : u[f]) {
            ind[j]--;
            if (ind[j] == 0) q.push(j);
        }
    }
    return true;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    FO(i,0,m) {
        scanf("%d %d", &e[i].first, &e[i].second);
        e[i].first--; e[i].second--;
    }
    int s = 0, en = m, b = -1;
    while (s <= en) {
        int md = (s+en)/2;
        if (uniq(md)) {
            b = md;
            en = md-1;
        } else {
            s = md+1;
        }
    }
    printf("%d\n", b);
}