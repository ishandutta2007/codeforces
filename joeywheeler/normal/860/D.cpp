#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
int s[200005];
vector<int> u[200005];
int T;
vector<tuple<int,int,int> > res;

bool go(int i, int par) {
    int mt = 0;

    s[i] = ++T;
    for (int j : u[i]) if (j != par) {
        bool us = false;
        if (!s[j]) {
            us = go(j,i);
        } else {
            us = s[j] > s[i];
        }
        if (us) {
            if (!mt) mt = j;
            else {
                res.emplace_back(mt, i, j);
                mt = 0;
            }
        }
    }
    if (mt && par) {
        res.emplace_back(mt, i, par);
        return false;
    } else return true;
}

int main() {
    scanf("%d %d", &n, &m);
    fo(i,0,m) {
        int x, y; scanf("%d %d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    fo(i,1,n+1) if (!s[i]) go(i,0);
    printf("%d\n", sz(res));
    for (auto p : res) {
        int x, y, z; tie(x,y,z) = p;
        printf("%d %d %d\n", x, y, z);
    }
}