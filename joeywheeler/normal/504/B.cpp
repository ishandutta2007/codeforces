#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int b[200005];

void u(int i, int v) {
    i++;
    for (;i<200005;i+=i&-i) b[i]+=v;
}

int q(int i) {
    i++;
    int r=0;
    for (;i>0;i-=i&-i) r+=b[i];
    return r;
}

int n;

void X(int *a, int *o) {
    memset(b,0,sizeof b);
    FO(i,0,n) u(i,1);
    FO(i,0,n) {
        o[i] = q(a[i])-1;
        u(a[i],-1);
    }
}

void IX(int *a, int *o) {
    memset(b,0,sizeof b);
    FO(i,0,n) u(i,1);
    FO(i,0,n) {
        int s = 0, e = n-1, best = -1;
        while (s<=e) {
            int m = (s+e)/2;
            if (q(m) > a[i]) {
                best = m;
                e = m-1;
            } else s = m+1;
        }
        o[i] = best;
        u(best,-1);
    }
}

int a[200005], aa[200005], B[200005], bb[200005];
int r[200005], rr[200005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);
    FO(i,0,n) scanf("%d", B+i);

    X(a,aa); X(B,bb);

    int carry = 0;
    for (int i = n-1; i >= 0; i--) {
        int l = carry + aa[i] + bb[i];
        rr[i] = l % (n-i);
        carry = l / (n-i);
    }
    
    IX(rr,r);

    FO(i,0,n) printf("%d%c", r[i], " \n"[i==n-1]);
}