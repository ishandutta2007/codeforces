#include <bits/stdc++.h>

using namespace std;

const int AL = 28;
const int N = 600500;

typedef long long int64;

int npt = 0;
struct node;

node* nds[N];

struct node {
    node* to[AL];
    node* suf;
    int num;
    int len;
    int ca, cb, cc;
    node(int _len) {
        memset(to, 0, sizeof(to));
        len = _len;
        suf = NULL;
        nds[num = npt++] = this;
        ca = cb = cc = 0;
    }
    node(node* b, int _len) {
        memset(to, 0, sizeof(to));
        len = _len;
        memcpy(to, b->to, sizeof(to));
        suf = b->suf;
        nds[num = npt++] = this;
        ca = cb = cc = 0;
    }
};

node *root = new node(0), *last = root;

vector<int> E[N];

void add(char c) {
    node* pt = last;
    last = new node(last->len + 1);
    for (; pt != NULL && pt->to[c] == NULL; pt = pt->suf) pt->to[c] = last;
    if (!pt) return void(last->suf = root);
    if (pt->to[c]->len == pt->len + 1) return void(last->suf = pt->to[c]);
    node* old = pt->to[c];
    node* nw = new node(old, pt->len + 1);
    old->suf = last->suf = nw;
    for (; pt != NULL && pt->to[c] == old; pt = pt->suf) pt->to[c] = nw;
}

const int64 MOD = 1000 * 1000 * 1000 + 7;

int D[N];

void DFS(int x) {
    for (int i = 0; i < E[x].size(); ++i) {
        int y = E[x][i];
        DFS(y);
        nds[x]->ca += nds[y]->ca;
        nds[x]->ca %= MOD;
        nds[x]->cb += nds[y]->cb;
        nds[x]->cb %= MOD;
        nds[x]->cc += nds[y]->cc;
        nds[x]->cc %= MOD;
    }
    if (x) {
        int64 cur = nds[x]->ca;
        cur *= nds[x]->cb;
        cur %= MOD;
        cur *= nds[x]->cc;
        cur %= MOD;
        D[nds[x]->suf->len] = (D[nds[x]->suf->len] + cur) % MOD;
        D[nds[x]->len] = (D[nds[x]->len] + MOD - cur) % MOD;
    }
}

char A[N], B[N], C[N];

int main() {
    gets(A);
    int nA = strlen(A);
    gets(B);
    int nB = strlen(B);
    gets(C);
    int nC = strlen(C);
    for (int i = 0; i < nA; ++i) add(A[i] - 'a');
    add('z' + 1 - 'a');
    for (int i = 0; i < nB; ++i) add(B[i] - 'a');
    add('z' + 2 - 'a');
    for (int i = 0; i < nC; ++i) add(C[i] - 'a');
    node* cur;
    cur = root;
    for (int i = 0; i < nA; ++i) {
        cur = cur->to[A[i] - 'a'];
        assert(cur);
        cur->ca++;
    }
    cur = root;
    for (int i = 0; i < nB; ++i) {
        cur = cur->to[B[i] - 'a'];
        assert(cur);
        cur->cb++;
    }
    cur = root;
    for (int i = 0; i < nC; ++i) {
        cur = cur->to[C[i] - 'a'];
        assert(cur);
        cur->cc++;
    }
    for (int i = 1; i < npt; ++i) E[nds[i]->suf->num].push_back(i);
    DFS(0);
    int sum = 0;
    for (int i = 0; i <= min(nA, min(nB, nC)); ++i) {
        if (i) printf("%d ", sum);
        sum += D[i];
        sum %= MOD;
    }
    printf("\n");
}