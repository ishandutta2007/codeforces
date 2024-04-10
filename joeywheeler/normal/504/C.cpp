#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MN 100005

using namespace std;

typedef long long ll;

int n, a[MN];
bool mid = false;

bool isp() {
    FO(i,0,n) if (a[i] != a[n-i-1]) return false;
    return true;
}

int COUNT[MN];
bool canp() {
    FO(i,0,n) COUNT[a[i]]++;
    int no = 0;
    FO(i,0,MN) if (COUNT[i]&1) no++;
    return no <= 1;
}

int IN[MN], NM[MN], nondom;

void modin(int x, int v) {
    if (IN[x] < NM[x]) nondom--;
    IN[x] += v;
    if (IN[x] < NM[x]) nondom++;
}

void modnm(int x, int v) {
    if (IN[x] < NM[x]) nondom--;
    NM[x] += v;
    if (IN[x] < NM[x]) nondom++;
}

int ffail, lfail;
int s, e;

bool in(int i) {
    return s <= i && i < e;
}

bool good() {
    if (!in(ffail) || !in(lfail)) {
        int FF = n-ffail-1, LL=n-lfail-1;
        if (!in(FF) || !in(LL)) {
            return false;
        }
    }

    if (mid && !in(n/2)) return false;
    if (nondom) return false;

    return true;
}

void add(int i) {
    int o = n-i-1;

    if (i != o) {
        if (in(o)) modnm(a[i],-1);
        else modnm(a[o],1);
    }

    modin(a[i],1);
}

void rem(int i) {
    int o = n-i-1;

    if (i != o) {
        if (in(o)) modnm(a[i],1);
        else modnm(a[o],-1);
    }

    modin(a[i],-1);
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);

    if (isp()) {
        printf("%lld\n", n*1ll*(n+1)/2);
        return 0;
    }

    if (!canp()) {
        printf("0\n");
        return 0;
    }

    mid = (n&1) && (COUNT[a[n/2]]%2==0);

    lfail = -1;
    FO(i,0,n/2) if (a[i] != a[n-i-1]) {
        if (lfail == -1) lfail = i;
        ffail = i;
    }

    ll res = 0;

    for (s=0;s<n;) {
        while (s==e || !good()) {
            if (e==n) {
                e = n+1;
                break;
            }
            add(e);
            e++;
        }
        if (e==n+1) break;
        res += n-e+1;
        rem(s);
        s++;
    }

    printf("%lld\n", res);
}