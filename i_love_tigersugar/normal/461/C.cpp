#include<cstdio>
#include<vector>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
class BIT {
    private:
    int n;
    vector<int> v;
    public:
    BIT() {
        n=0;
    }
    BIT(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x,int d) {
        if (x<1 || x>n) return;
        for (;x<=n;x+=x&-x) v[x]+=d;
    }
    int get(int x) const {
        if (x<1 || x>n) return (0);
        int ret=0;
        for (;x>=1;x&=x-1) ret+=v[x];
        return (ret);
    }
    int get(int l,int r) const {
        return (get(r)-get(l-1));
    }
};
BIT bit;
int n,q;
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
void process(void) {
    n=nextInt();
    q=nextInt();
    bit=BIT(n);
    FOR(i,1,n) bit.update(i,1);
    int L=1;
    int R=n;
    REP(zz,q) {
        if (nextInt()==1) {
            int p=nextInt();
            if (L<R && p<=R-L+1-p) {
                REP(i,p) {
                    int t=bit.get(L+i,L+i);
                    bit.update(L+i,-t);
                    bit.update(2*(L+p)-1-(L+i),t);
                }
                L=L+p;
            }
            else if (L<R && p>R-L+1-p) {
                REP(i,R-L+1-p) {
                    int t=bit.get(R-i,R-i);
                    bit.update(R-i,-t);
                    bit.update(2*(L+p)-1-(R-i),t);
                }
                R=L;
                L=L+p-1;
            }
            else if (L>R && p<=L-R+1-p) {
                REP(i,p) {
                    int t=bit.get(L-i,L-i);
                    bit.update(L-i,-t);
                    bit.update(2*(L-p)+1-(L-i),t);
                }
                L=L-p;
            }
            else {
                REP(i,L-R+1-p) {
                    int t=bit.get(R+i,R+i);
                    bit.update(R+i,-t);
                    bit.update(2*(L-p)+1-(R+i),t);
                }
                R=L;
                L=L-p+1;
            }
        }
        else {
            int l=nextInt();
            int r=nextInt();
            if (L<=R) printf("%d\n",bit.get(l+L,r+L-1));
            else printf("%d\n",bit.get(L+1-r,L-l));
        }
    }
}
int main(void) {
    process();
    return 0;
}