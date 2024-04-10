#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;
pair<int,int> e[400005];
int ne;
int ss[400005];
int tt[400005];
pair<int,int> bex[400005][3];
int mxv[400005];
int nv[400005];

int a[400005];
int b[400005];

vector<int> u[400005];

int ei(int i, int j) {
    return lower_bound(e,e+ne,make_pair(i,j))-e;
}

// taken i->j, at j
int cdp(int i, int j) {
    int ed = ei(i,j);
    if (ss[ed] != -1) return ed;
    nv[j]++;

    ss[ed] = 0;
    mxv[ed] = 0;
    if (nv[j] <= 2) {
        ss[ed] = 1;
        int bextra = 0;
        for (int k : u[j]) if (k != i) {
            int oe = cdp(j,k);
            ss[ed] += ss[oe];
            if (mxv[oe] == ss[oe]) {
                mxv[ed] += mxv[oe];
            } else {
                bextra = max(bextra, mxv[oe]);
            }
        }
        mxv[ed] += bextra;

        if (nv[j] == 2) {
            tt[j] = 0;
            FO(z,0,3) bex[j][z] = make_pair(0,-z-1);
            for (int k : u[j]) {
                int oe = cdp(j,k);
                if (mxv[oe] == ss[oe]) {
                    tt[j] += mxv[oe];
                } else {
                    bex[j][2] = make_pair(mxv[oe],oe);
                    sort(bex[j],bex[j]+3); reverse(bex[j],bex[j]+3);
                }
            }
        }
    } else {
        int re = cdp(j,i);
        ss[ed] = n - ss[re];
        mxv[ed] = tt[j];
        if (mxv[re] == ss[re]) mxv[ed] -= mxv[re];
        FO(z,0,3) if (bex[j][z].second != re) {
            mxv[ed] += bex[j][z].first;
            break;
        }
    }
    if (b[j] == 0) mxv[ed] = 0;
    else mxv[ed]++;

    return ed;
}

bool can(int x) {
    FO(i,0,n) b[i] = a[i] >= x;
    memset(ss,-1,sizeof ss);
    memset(mxv,-1,sizeof mxv);
    memset(nv,0,sizeof nv);

    FO(i,0,ne) {
        int ei = cdp(e[i].first, e[i].second);
        //printf("ss %d->%d: %d\n", e[i].first, e[i].second, ss[ei]);
        //printf("mxv %d->%d: %d\n", e[i].first, e[i].second, mxv[ei]);
    }

    FO(j,0,n) if (b[j]) {
        int dp = 1;
        int bextra = 0;
        for (int k : u[j]) {
            int oe = cdp(j,k);
            if (mxv[oe] == ss[oe]) {
                dp += mxv[oe];
            } else {
                bextra = max(bextra, mxv[oe]);
            }
        }
        dp += bextra;
        if (dp >= k) return true;
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    FO(i,0,n) scanf("%d", a+i);
    FO(i,0,n-1) {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        u[x].push_back(y);
        u[y].push_back(x);
        e[ne++] = make_pair(x,y);
        e[ne++] = make_pair(y,x);
    }
    sort(e,e+ne);

    int st = 0, en = 1000005, bst = 0;
    while (st <= en) {
        int md = (st+en)/2;
        if (can(md)) {
            //printf("CAN %d\n", md);
            bst = md;
            st = md+1;
        } else {
            //printf("CANT %d\n", md);
            en = md-1;
        }
    }
    printf("%d\n", bst);
}