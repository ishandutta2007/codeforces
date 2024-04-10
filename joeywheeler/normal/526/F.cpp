#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n;
int v[300005];
int curg[300005];
int seen[300005];
int mxv[300005];
int mnv[300005];
int LS;
ll res;

int a, b;
int cmx, cmn;

map<int,int> neither, mx, mn, both;

int get(const map<int,int> &a, int b) {
    auto f = a.find(b);
    if (f != a.end()) return f->second;
    else return 0;
}

void cg(int i) {
    if (seen[i] != LS) {
        seen[i] = LS;
        curg[i] = -1;
    }
    if (curg[i] == 0) {
        neither[+i] -= 1;
    } else if (curg[i] == 1) {
        mx[mxv[i]+i] -= 1;
    } else if (curg[i] == 2) {
        mn[-mnv[i]+i] -= 1;
    } else if (curg[i] == 3) {
        both[mxv[i]-mnv[i]+i] -= 1;
    }

    bool dmx = mxv[i] >= cmx;
    bool dmn = mnv[i] <= cmn;
    if (dmx && dmn) {
        curg[i] = 3;
    } else if (dmx) {
        curg[i] = 1;
    } else if (dmn) {
        curg[i] = 2;
    } else curg[i] = 0;

    //printf("curg[%d]=%d\n", i, curg[i]);

    if (curg[i] == 0) {
        neither[+i] += 1;
    } else if (curg[i] == 1) {
        mx[mxv[i]+i] += 1;
    } else if (curg[i] == 2) {
        mn[-mnv[i]+i] += 1;
    } else if (curg[i] == 3) {
        both[mxv[i]-mnv[i]+i] += 1;
    }
}

void go(int _a, int _b) {
    ++LS;
    a = _a; b = _b;

    if (b-a < 0) return;
    int md = (a+b)/2;
    int _md = md;

    int fdmx = md, fdmn = md;

    mxv[md] = mnv[md] = cmx = cmn = v[md];
    for (int i = md-1; i >= a; i--) {
        mxv[i] = max(mxv[i+1], v[i]);
        mnv[i] = min(mnv[i+1], v[i]);
    }

    for (int i = md+1; i <= b; i++) {
        mxv[i] = max(mxv[i-1], v[i]);
        mnv[i] = min(mnv[i-1], v[i]);
    }

    //printf("a,md,b=%d,%d,%d\n", a, md, b);
    //FO(i,a,b+1) printf("i,mxv,mnv=%d,%d,%d\n", i, mxv[i], mnv[i]);

    for (int i = a; i <= md; i++) cg(i);

    for (int i = md; i <= b; i++) {
        //printf("i=%d\n", i);
        cmx = mxv[i]; cmn = mnv[i];
        while (fdmx >= a && mxv[fdmx] < cmx) {
            cg(fdmx);
            fdmx--;
            //printf("FDMX BACK\n");
        }
        while (fdmn >= a && mnv[fdmn] > cmn) {
            cg(fdmn);
            fdmn--;
            //printf("FDMN BACK\n");
        }
        res += get(neither,-cmx+cmn+i);
        res += get(both,+i);
        res += get(mx,cmn+i);
        res += get(mn,-cmx+i);
        //printf("-cmx-i=%d\n", -cmx+i);
    }
    //printf("res=%lld\n", res);

    neither.clear(); mx.clear(); mn.clear(); both.clear();
    go(_a,_md-1); go(_md+1,_b);
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x, y; scanf("%d %d", &x, &y);
        v[x-1] = y;
    }
    //FO(i,0,n) printf("v[%d]=%d\n", i, v[i]);
    go(0,n-1);
    printf("%lld\n", res);
}