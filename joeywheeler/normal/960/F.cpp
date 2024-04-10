#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define eb emplace_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n, m;
map<ll,int> mp[100005];
int res = 0;

void go(int x, int y, int w) {
    auto it = --mp[x].lower_bound(w);
    int ln = it->second + 1;
    while (1) {
        it = mp[y].lower_bound(w);
        if (it == mp[y].end()) break;
        if (it->second <= ln) {
            mp[y].erase(it);
        } else {
            break;
        }
    }
    --it;
    if (it->second >= ln) return;
    mp[y][w] = ln;
    res = max(res, ln);
}

int main() {
    scanf("%d %d", &n, &m);
    fo(i,1,n+1) mp[i][-1] = 0;
    fo(i,0,m) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        go(x,y,w);
    }
    printf("%d\n", res);
}