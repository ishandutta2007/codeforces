#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <vector>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef struct _node {
    _node *nxt[20];
    _node *fail;
    int c;

    int cache[2][2][205][505];

    _node() {
        FO(i,0,20) nxt[i] = 0;
        memset(cache, -1, sizeof cache);
        c = 0;
        fail = 0;
    }
} *node;

node root = new _node;

vector<int> l, r;
int n, N, m, k;

void read(vector<int> &v) {
    int s;
    scanf("%d", &s);
    v.resize(s);
    FO(i,0,s) scanf("%d", &v[i]);
}

void insert(node r, vector<int> &t, int i, int c) {
    if (i == t.size()) r->c += c;
    else {
        if (!r->nxt[t[i]]) r->nxt[t[i]] = new _node;
        insert(r->nxt[t[i]], t, i+1, c);
    }
}

void pad(vector<int> &v, int s) {
    vector<int> tmp = v;
    FO(i,0,s-sz(tmp)) v.push_back(0);
    FO(i,0,s-sz(tmp)) v[i] = 0;
    FO(i,s-sz(tmp),sz(v)) v[i] = tmp[i-(s-sz(tmp))];
}

int dp(node nd, int hl, int hr, int i, int c) {
    c -= nd->c;
    if (c < 0) return 0;
    if (i == N) {
        return 1;
    }
    int &R = nd->cache[hl][hr][i][c];
    if (R != -1) return R;

    long long res = 0;
    FO(j,0,m) {
        if (hl && j < l[i]) continue;
        if (hr && j > r[i]) continue;
        res += dp(nd->nxt[j], hl && j==l[i], hr && j==r[i], i+1, c);
        res %= 1000000007;
    }
    return R = res;
}

int score(vector<int> v) {
    int s = 0;
    node r = root;
    FO(i,0,sz(v)) {
        printf("%p -> %p\n", r, r->nxt[v[i]]);
        r = r->nxt[v[i]];
        s += r->c;
    }
    return s;
}

void print(vector<int> v) {
    FO(i,0,sz(v)) printf(" %d", v[i]);
}

void fill_links(node r, vector<int> &cp) {
    r->fail = root;
    FO(j,1,sz(cp)) {
        node tmp = root;
        FO(k,j,sz(cp)) {
            if (tmp == 0) break;
            else {
                tmp = tmp->nxt[cp[k]];
            }
        }
        if (tmp) {
            r->fail = tmp;
            break;
        }
    }

    FO(i,0,m) if (r->nxt[i]) {
        cp.push_back(i);
        fill_links(r->nxt[i], cp);
        cp.pop_back();
    }
}

void fc() {
    queue<node> q;
    set<node> seen;
    q.push(root); seen.insert(root);
    FO(i,0,m) if (!root->nxt[i]) root->nxt[i] = root;
    while (!q.empty()) {
        node f = q.front();
        q.pop();

        f->c += f->fail->c;

        FO(i,0,m) if (!f->nxt[i]) {
            f->nxt[i] = f->fail->nxt[i];
        } else {
            if (!seen.count(f->nxt[i])) {
                q.push(f->nxt[i]);
                seen.insert(f->nxt[i]);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    read(l); read(r);
    FO(i,0,n) {
        vector<int> tmp;
        read(tmp);
        int c;
        scanf("%d", &c);
        insert(root, tmp, 0, c);
    }
    vector<int> cp;
    if (l.size() < r.size()) pad(l,r.size());
    else pad(r,l.size());

    fill_links(root, cp);
    fc();

    N = l.size();

    //print(l);
    //print(r);

    long long res = 0;
    FO(i,0,N) {
        FO(j,1,m) {
            if (j >= l[i] && (i > 0 || j <= r[i])) {
                res += dp(root->nxt[j], j == l[i], i == 0 && j == r[i], i+1, k);
                res %= 1000000007;
            }
        }
        if (l[i] != 0) break;
    }
    printf("%d\n", int(res));
}