#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct p {
    int x, y, i;
};

p l[100005];
int n, k;

bool xc(p a, p b) {
    return a.x < b.x;
}

bool yc(p a, p b) {
    return a.y < b.y;
}

bool ic(p a, p b) {
    return a.i < b.i;
}

int f[4][20];
bool del[100005];
long long ans = 2e18;

void go(int ck) {
    int a,b,c,d;
    FO(i,0,k+1) if (!del[f[0][i]]) {a = f[0][i]; break;}
    FO(i,0,k+1) if (!del[f[1][i]]) {b = f[1][i]; break;}
    FO(i,0,k+1) if (!del[f[2][i]]) {c = f[2][i]; break;}
    FO(i,0,k+1) if (!del[f[3][i]]) {d = f[3][i]; break;}
    //printf("%d %d %d %d\n", a, b, c, d);
    int w = (l[b].x-l[a].x+1)/2;
    w = max(w,1);
    int h = (l[d].y-l[c].y+1)/2;
    h = max(h,1);
    long long tans = w*1ll*h;
    ans = min(ans, tans);
    if (ck < k) {
        del[a] = true;
        go(ck+1);
        del[a] = false;
        del[b] = true;
        go(ck+1);
        del[b] = false;
        del[c] = true;
        go(ck+1);
        del[c] = false;
        del[d] = true;
        go(ck+1);
        del[d] = false;
    }
}

int main() {
    scanf("%d%d", &n, &k);
    FO(i,0,n) {
        int x1,y1,x2,y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        l[i].x = x1+x2;
        l[i].y = y1+y2;
        l[i].i = i;
    }

    sort(l,l+n,xc);
    FO(i,0,k+1) {
        f[0][i] = l[i].i;
    }
    reverse(l,l+n);
    FO(i,0,k+1) {
        f[1][i] = l[i].i;
    }
    sort(l,l+n,yc);
    FO(i,0,k+1) {
        f[2][i] = l[i].i;
    }
    reverse(l,l+n);
    FO(i,0,k+1) {
        f[3][i] = l[i].i;
    }
    sort(l,l+n,ic);
    go(0);
    printf("%lld\n", ans);
}