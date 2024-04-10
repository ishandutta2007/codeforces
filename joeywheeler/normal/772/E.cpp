#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> u[3005];
int pr[3005];
int cnd, ort, csv;

bool iv[3005];
int ts[3005];
int ms[3005];

int n;

void go2(int i) {
    ts[i] = 0;
    ms[i] = 0;
    for (int j : u[i]) if (iv[j]) {
        go2(j);
        ts[i] += ts[j];
        ms[i] = max(ms[i], ts[j]);
    }
    ts[i] += 1;
    ms[i] = max(ms[i], csv-ts[i]);
}

void gv(int i, vector<int> &v) {
    if (!iv[i]) return;
    else {
        v.push_back(i);
        for (int j : u[i]) gv(j, v);
    }
}

void addl(int i, int l) {
    int p = pr[i];
    if (p != -1) {
        for (int &j : u[p]) if (j == i) {
            j = cnd;
        }
    } else {
        ort = cnd;
    }
    u[cnd].push_back(i);
    u[cnd].push_back(l);
    pr[i] = cnd;
    pr[l] = cnd;
    pr[cnd] = p;
    cnd++;
}

int gc(int i) {
    while (i > n) i = u[i][0];
    return i;
}

int bbq(int i, int l) {
    if (i <= n) return 2;
    else {
        printf("%d %d %d\n", gc(u[i][0]), gc(u[i][1]), l);
        fflush(stdout);
        char c;
        scanf(" %c", &c);
        if (c == 'X') {
            return 2;
        } else if (c == 'Y') {
            return 1;
        } else {
            return 0;
        }
    }
}

void go(int i, vector<int> v, int rt) {
    FO(j,0,cnd) iv[j] = false;
    for (int j : v) iv[j] = true;
    csv = sz(v);
    go2(rt);

    //FO(l,0,cnd) if (iv[l]) printf("%d ", l);
    //printf("\n");

    int bq = -1;
    for (int j : v) if (ms[j] <= csv/2) {
        bq = j;
    }

    int dir = bbq(bq, i);

    //printf("dir = %d\n", dir);
    //printf("bq = %d\n", bq);

    vector<int> nv;
    int nrt;
    if (dir <= 1) {
        gv(u[bq][dir], nv);
        nrt = u[bq][dir];
        if (sz(nv) == 0) {
            addl(u[bq][dir], i);
            return;
        }
    } else {
        gv(bq, nv);
        for (int j : nv) {
            iv[j] = false;
        }
        nv.clear();
        FO(j,0,cnd) if (iv[j]) nv.push_back(j);
        nrt = rt;
        if (sz(nv) == 0) {
            addl(bq, i);
            return;
        }
    }

    go(i, nv, nrt);
}

int main() {
    scanf("%d", &n);
    cnd = n+1;
    u[cnd].push_back(1);
    u[cnd].push_back(2);
    pr[1] = pr[2] = cnd;
    pr[cnd] = -1;
    ort = cnd;
    cnd++;

    FO(i,3,n+1) {
        vector<int> v;
        FO(j,1,i) v.push_back(j);
        FO(j,n+1,cnd) v.push_back(j);
        go(i, v, ort);
    }

    printf("-1\n");
    FO(i,1,cnd) printf("%d%c", pr[i], " \n"[i+1==cnd]);
    fflush(stdout);
}