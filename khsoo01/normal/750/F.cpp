#include<bits/stdc++.h>
using namespace std;
int t, h, n, cc, xx;
bool inpath[130];
vector<int> adj[130], path;

void getof (int idx) {
    if(adj[idx].size()) return;
    printf("? %d\n",idx);
    fflush(stdout);
    int tmp;
    scanf("%d",&tmp);
    for(int i=1;i<=tmp;i++) {
        int tt;
        scanf("%d",&tt);
        adj[idx].push_back(tt);
    }
}

void init() {
    for(int i=1;i<=n;i++) {
        inpath[i] = false;
        adj[i].clear();
    }
    path.clear();
    cc = 0; xx = 0;
}

bool frontpush (int cur, int prv) {
    getof(cur);
    path.push_back(cur);
    inpath[cur] = true;
    if(adj[cur].size() == 2) {
        printf("! %d\n",cur);
        return true;
    }
    else if(adj[cur].size() == 1) return false;
    return frontpush((adj[cur][0] == prv ? adj[cur][1] : adj[cur][0]), cur);
}

bool backpush (int cur, int prv) {
    getof(cur);
    if(adj[cur].size() == 2) {
        printf("! %d\n",cur);
        return true;
    }
    else if(adj[cur].size() == 1) {
        path.push_back(cur);
        inpath[cur] = true;
        return false;
    }
    if(backpush((adj[cur][0] == prv ? adj[cur][1] : adj[cur][0]), cur)) return true;
    path.push_back(cur);
    inpath[cur] = true;
    return false;
}

bool dfs (int cur, int prv, int dst) {
    if(dst == xx) {
        if(cc == ((1<<xx)-1)) {
            printf("! %d\n",cur);
            return true;
        }
        else {
            getof(cur);
            if(adj[cur].size() == 2) {
                printf("! %d\n",cur);
                return true;
            }
            else cc++;
        }
        return false;
    }
    else {
        getof(cur);
        for(int i=0;i<adj[cur].size();i++) {
            if(adj[cur][i] != prv) {
                if(dfs(adj[cur][i], cur, dst+1)) return true;
            }
        }
        return false;
    }
}

int src (int cur, int prv, int lft) {
    getof(cur);
    if(adj[cur].size() == 2) {
        printf("! %d\n",cur);
        return 2;
    }
    if(lft == 0) {
        if(adj[cur].size() == 1) return 0;
        else return 1;
    }
    else {
        for(int i=0;i<adj[cur].size();i++) {
            if(adj[cur][i] == prv) continue;
            int tmp = src(adj[cur][i], cur, lft-1);
            return tmp;
        }
    }
}

void calc (int cur, int nein, int ch) {
    if(h - ch <= 2) {
        xx = h - ch;
        dfs(cur, nein, 0);
    }
    else {
        int nxt = -1;
        getof(cur);
        for(int i=0;i<adj[cur].size();i++) {
            if(adj[cur][i] != nein) {
                nxt = adj[cur][i];
                break;
            }
        }
        int tmp = src(nxt, cur, ch-2);
        if(tmp == 2) return;
        else if(tmp == 1) calc(nxt, cur, ch+1);
        else {
            for(int i=0;i<adj[cur].size();i++) {
                if(adj[cur][i] != nein && adj[cur][i] != nxt) {
                    calc(adj[cur][i], cur, ch+1);
                    break;
                }
            }
        }
    }
}

void solve () {
    scanf("%d",&h);
    n = (1<<h) - 1;
    init();
    getof(1);
    if(adj[1].size() == 2) {
        printf("! 1\n");
        fflush(stdout);
        return;
    }
    inpath[1] = true;
    if(adj[1].size() == 1) {
        path.push_back(1);
        if(frontpush(adj[1][0], 1)) {
            fflush(stdout);
            return;
        }
    }
    else {
        if(backpush(adj[1][0], 1)) {
            fflush(stdout);
            return;
        }
        path.push_back(1);
        if(frontpush(adj[1][1], 1)) {
            fflush(stdout);
            return;
        }
    }
    int cen = path[path.size()/2];
    for(int i=0;i<adj[cen].size();i++) {
        if(!inpath[adj[cen][i]]) {
            calc(adj[cen][i], cen, path.size()/2+2);
            break;
        }
    }
    fflush(stdout);
}

int main()
{
    scanf("%d",&t);
    while(t--) solve();
}