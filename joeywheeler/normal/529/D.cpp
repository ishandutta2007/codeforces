#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n,m,t,nu,mnu;
map<int,int> c;
int r, a[20005];

deque<pair<int,int>> q;

int main() {
    scanf("%d%d%d", &n, &m, &t);
    FO(i,0,n) {
        int x,y,z; scanf("%d:%d:%d", &x, &y, &z);
        int s = x*60*60 + y*60 + z;
        while (sz(q) && q.front().first+t <= s) {
            int S, I; tie(S,I) = q.front(); q.pop_front();
            c[I]--;
            if (c[I] == 0) nu--;
        }
        if (nu < m) {
            ++r;
            c[r]++; nu++; mnu = max(mnu,nu);
            a[i] = r;
        } else {
            c[a[i] = q.back().second]++;
        }
        q.push_back({s,a[i]});
    }
    if (mnu != m) printf("No solution\n");
    else {
        printf("%d\n", r);
        FO(i,0,n) printf("%d\n", a[i]);
    }
}