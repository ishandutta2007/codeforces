#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
class SegmentTree {
    private:
    vector<bool> lazy;
    int n;
    void update(int i,int l,int r,int u,int v) {
        if (l>v || r<u || l>r || v<u) return;
        if (u<=l && r<=v) {
            lazy[i]=true;
            return;
        }
        int m=(l+r)>>1;
        update(2*i,l,m,u,v);
        update(2*i+1,m+1,r,u,v);
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        lazy.assign(4*n+7,false);
    }
    void update(int l,int r) {
        update(1,1,n,l,r);
    }
    bool get(int x) const {
        int i=1;
        int l=1;
        int r=n;
        while (true) {
            if (lazy[i]) return (true);
            if (l==r) return (false);
            int m=(l+r)>>1;
            if (x>m) {
                i=2*i+1;
                l=m+1;
            } else {
                i=2*i;
                r=m;
            }
        }
    }
};
char s[MAX];
int n,k;
int z[MAX];
void init(void) {
    scanf("%d%d",&n,&k);
    scanf("%s",s);
}
void process(void) {
    int L=0;
    int R=0;
    FOR(i,1,n-1) {
        if (i>R) {
            L=R=i;
            while (R<n && s[R-L]==s[R]) R++;
            z[i]=R-L;
            R--;
        }
        else {
            int k=i-L;
            if (z[k]<R-i+1) z[i]=z[k];
            else {
                L=i;
                while (R<n && s[R-L]==s[R]) R++;
                z[i]=R-L;
                R--;
            }
        }
    }
    z[0]=n;
    SegmentTree myit(n);
    FOR(i,1,n) {
        int tmp=1;
        while ((tmp+1)*i<=n && z[tmp*i]>=i) tmp++;
        if (tmp<k) continue;
        int l=i*k;
        myit.update(l,min(n,l+min(i,z[l])));
        //printf("For %d update %d to %d\n",i,l,l+i);
    }
    FOR(i,1,n) printf("%d",myit.get(i)?1:0);
    printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}