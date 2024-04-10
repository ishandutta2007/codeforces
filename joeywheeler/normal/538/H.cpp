#include <bits/stdc++.h>

#define mp make_pair

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int l[200005], r[200005];
int n, m;

vector<int> adj[200005];
int seen[200005];

int L[2], R[2];

int nl[200005], nr[200005];
int k;

void go(int i, int c) {
    if (seen[i] == 3-c) {
        printf("IMPOSSIBLE\n");
        exit(0);
    } else if (!seen[i]) {
        seen[i] = c;
        L[c-1] = max(L[c-1], l[i]);
        R[c-1] = min(R[c-1], r[i]);
        for (int j : adj[i]) go(j,3-c);
    }
}

int n1;

pair<int,int> getseg(int i) {
    if (i&1) i ^= 1;
    bool g0 = l[i] <= n1 && n1 < r[i];
    bool g1 = l[i+1] <= n1 && n1 < r[i+1];
    if (g0 && g1) {
        return mp(min(l[i],l[i+1]), max(r[i],r[i+1]));
    } else if (g0) {
        return mp(l[i+1], r[i+1]);
    } else if (g1) {
        return mp(l[i], r[i]);
    } else {
        return mp(1e9+10, 0);
    }
}

multiset<int> al, ar;

bool inthing[200005];

void addseg(pair<int,int> p) {
    //printf("ADDSEG [%d,%d)\n", p.first, p.second);
    al.insert(p.first);
    ar.insert(p.second);
}

void remseg(pair<int,int> p) {
    //printf("REMSEG [%d,%d)\n", p.first, p.second);
    al.erase(al.find(p.first));
    ar.erase(ar.find(p.second));
}

vector<int> comp;
int col[100005];

void dfs(int i, int c) {
    if (!col[i]) {
        col[i] = c;
        comp.push_back(i);
        for (int j : adj[i]) dfs(j,3-c);
    }
}

void ans(int n0, int n1) {
    int t, T;
    rewind(stdin);
    scanf("%d %d", &t, &T);
    scanf("%d %d", &n, &m);
    FO(i,0,n) scanf("%d %d", l+i, r+i);
    FO(i,0,n) if (!col[i]) {
        comp.clear();
        dfs(i,1);
        int w = 2|4;
        for (int x : comp) {
            bool g0 = l[x] <= n0 && n0 <= r[x];
            bool g1 = l[x] <= n1 && n1 <= r[x];
            if (!g0) w &= ~(1<<col[x]);
            if (!g1) w &= ~(1<<(3-col[x]));
        }
        assert(w);
        for (int x : comp) {
            if (~w&2) {
                col[x] = 3-col[x];
            }
        }
    }
    FO(i,0,n) printf("%d", col[i]);
    printf("\n");
}

int main() {
    int t, T;
    scanf("%d %d", &t, &T);
    scanf("%d %d", &n, &m);
    FO(i,0,n) {
        scanf("%d %d", l+i, r+i);
        r[i]++;
    }
    FO(i,0,m) {
        int x, y; scanf("%d %d", &x, &y); x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    FO(i,0,n) if (!seen[i]) {
        FO(j,0,2) L[j] = 0, R[j] = 1e9+10;
        go(i,1);

        FO(j,0,2) {
            if (L[j] >= R[j]) {
                printf("IMPOSSIBLE\n");
                exit(0);
            }
            nl[k] = L[j]; nr[k] = R[j];
            k++;
        }
    }
    FO(i,0,k) l[i] = nl[i], r[i] = nr[i];
    n = k;

    //FO(i,0,n) printf("%d %d\n", l[i], r[i]);

    vector<pair<int,int> > ev;
    FO(i,0,n) {
        inthing[i] = true;
        ev.push_back(make_pair(l[i],i));
        ev.push_back(make_pair(r[i],i));
    }
    sort(ev.begin(),ev.end());

    n1 = -1;
    FO(i,0,n) if (i%2 == 0) addseg(getseg(i));

    for (int i = 0; i < sz(ev); ) {
        int j;
        for (j = i; j < sz(ev) && ev[j].first == ev[i].first; j++) {
            if (inthing[ev[j].second]) {
                remseg(getseg(ev[j].second));
                inthing[ev[j].second] = 0;
                inthing[1^ev[j].second] = 0;
            }
        }
        n1 = ev[i].first;
        for (j = i; j < sz(ev) && ev[j].first == ev[i].first; j++) {
            if (!inthing[ev[j].second]) {
                addseg(getseg(ev[j].second));
                inthing[ev[j].second] = 1;
                inthing[1^ev[j].second] = 1;
            }
        }


        int l0 = n1, r0 = j<sz(ev) ? ev[j].first-1 : 1e9+10;
        int l1 = al.empty() ? 0 : *al.rbegin(), r1 = ar.empty() ? 1e9+10 : *ar.begin();
        r1--;

        //printf("[%d,%d] [%d,%d]\n", l0, r0, l1, r1);

        int m0 = l0, m1 = l1;
        m0 += max(min(r0-m0, T-m0-m1),0);
        m1 += max(min(r1-m1, T-m0-m1),0);
        if (l0 <= m0 && m0 <= r0 && l1 <= m1 && m1 <= r1 && t <= m0+m1 && m0+m1 <= T) {
            printf("POSSIBLE\n");
            printf("%d %d\n", m0, m1);
            ans(m0,m1);
            return 0;
        }
        i = j;
    }

    printf("IMPOSSIBLE\n");
}