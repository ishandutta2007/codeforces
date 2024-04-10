#include<bits/stdc++.h>
using namespace std;
int n;
int ax[200005],bx[200005],sx[200005];
int ap[200005],bp[200005],sp[200005];

struct segtree {
    int val[888888],lim;
    void init(int N) {
        for(lim=1;lim<=N;lim<<=1);
        for(int i=lim;i<2*lim;i++) val[i] = 1;
        for(int i=lim;--i;) {
            val[i] = val[2*i] + val[2*i+1];
        }
    }
    void update(int P, int V) {
        P += lim;
        while(P) {
            val[P] += V;
            P>>=1;
        }
    }
    int query(int S, int E) {
        int ret = 0;
        S += lim; E += lim;
        while(S<E) {
            if(S%2==1) ret += val[S++];
            if(E%2==0) ret += val[E--];
            S>>=1; E>>=1;
        }
        if(S==E) ret += val[S];
        return ret;
    }
    int kth(int K) {
        int cur = 1;
        if(K>=val[cur]) return -1;
        while(cur<lim) {
            if(val[2*cur]<=K) {
                K -= val[2*cur];
                cur = 2*cur+1;
            }
            else cur = 2*cur;
        }
        return cur-lim;
    }
}as,bs,ss;

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&ax[i]);
    for(i=0;i<n;i++) scanf("%d",&bx[i]);
    as.init(n); bs.init(n); ss.init(n);
    for(i=0;i<n;i++) {
        ap[i+1] = as.query(0,ax[i]-1);
        as.update(ax[i],-1);
        bp[i+1] = bs.query(0,bx[i]-1);
        bs.update(bx[i],-1);
    }
    for(i=n;i>0;i--) {
        sp[i] += ap[i] + bp[i];
        sp[i-1] += sp[i]/(n-i+1);
        sp[i] %= (n-i+1);
    }
    for(i=1;i<=n;i++) {
        sx[i] = ss.kth(sp[i]);
        ss.update(sx[i],-1);
        printf("%d ",sx[i]);
    }
}