#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
vector<int> la[200005], lb[200005];
int ans[200005];
vector<int> mine[200005];
int sat[200005];

vector<pair<int,int> > u[200005];

void go(int i);

void go2(int i) {
    if (sat[i]) return;
    //printf("%d is sat\n", i);
    sat[i] = 1;
    for (int x : mine[i]) go(x);
}

void go(int i) {
    //printf("go(%d)\n", i);
    for (int j = 0; j < sz(la[i]);) {
        if (sat[la[i][j]]) {
            swap(la[i][j],la[i].back());
            la[i].pop_back();
        } else j++;
    }
    for (int j = 0; j < sz(lb[i]);) {
        if (sat[lb[i][j]]) {
            swap(lb[i][j],lb[i].back());
            lb[i].pop_back();
        } else j++;
    }
    if (ans[i] == -1) {
        FO(j,0,sz(lb[i])) go2(lb[i][j]);
    } else if (ans[i] == 1) {
        FO(j,0,sz(la[i])) go2(la[i][j]);
    } else {
        if (sz(la[i]) == 0) {
            ans[i] = -1;
            go(i);
        } else if (sz(lb[i]) == 0) {
            ans[i] = 1;
            go(i);
        }
    }
}

bool oncyc[200005];
bool seen[200005];

int fcyc(int i, int le) {
    //printf("i=%d\n", i);
    if (oncyc[i]) {
        return i;
    }
    if (seen[i]) return -1;
    seen[i] = true;
    oncyc[i] = true;
    for (auto e : u[i]) {
        int j, ei; tie(j,ei) = e;
        if (ei != le) {
            //printf("%d->%d\n", i, j);
            int x = fcyc(j, ei);
            if (x != -1) {
                if (x == -2) return -2;
                //printf("CYCLE\n");

                // found cycle
                // direct ei from i to j

                if (!ans[i]) {
                    if (sz(la[ei]) && la[ei][0] == i) {
                        ans[ei] = 1;
                        go(ei);
                    } else if (sz(lb[ei]) && lb[ei][0] == i) {
                        ans[ei] = -1;
                        go(ei);
                    }
                }
                go(ei);

                return x == i ? -2 : x;
            }
        }
    }
    oncyc[i] = false;
    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,n) {
        int k; scanf("%d", &k);
        FO(j,0,k) {
            int x; scanf("%d", &x);
            mine[i].push_back(abs(x));
            if (x < 0) lb[-x].push_back(i);
            else la[x].push_back(i);
        }
    }
    FO(i,1,m+1) go(i);
    FO(i,1,m+1) go(i);

    FO(i,1,m+1) {
        //assert(sz(la[i]) + sz(lb[i]) == 0 ||
                //(sz(la[i]) == 1 && sz(lb[i]) == 1));
        if (sz(la[i]) + sz(lb[i])) {
            int x = la[i][0], y = lb[i][0];
            u[x].push_back(make_pair(y,i));
            u[y].push_back(make_pair(x,i));
        }
    }
    FO(i,0,n) fcyc(i,-1);
    FO(i,1,m+1) go(i);
    FO(i,0,n) if (!sat[i]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    FO(i,1,m+1) if (!ans[i]) ans[i] = -1;
    FO(i,1,m+1) printf("%d", ans[i] == -1 ? 0 : 1);
    printf("\n");
}