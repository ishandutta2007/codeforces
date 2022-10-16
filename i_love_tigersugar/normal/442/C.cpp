#include<bits/stdc++.h>
#define MAX   500500
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
inline void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
class BIT {
    private:
    int n;
    vector<int> v;
    void update(int x,int d) {
        if (x<1 || x>n) return;
        for (;x<=n;x+=x&(-x)) v[x]+=d;
    }
    public:
    BIT() {
        n=0;
    }
    BIT(int n) {
        this->n=n;
        v.assign(n+7,0);
        FOR(i,1,n) update(i,1);
    }
    void remove(int x) {
        update(x,-1);
    }
    int get(int x) const {
        if (x<1 || x>n) return (0);
        int ret=0;
        for (;x>=1;x&=x-1) ret+=v[x];
        return (ret);
    }
    int find(int pos) {
        int res=n+1;
        int cur=0;
        int mask=1;
        while (mask<=n) mask<<=1;
        mask>>=1;
        while (mask>0) {
            if ((cur|mask)<=n) {
                if (v[cur|mask]>=pos) minimize(res,cur|mask);
                else {
                    cur|=mask;
                    pos-=v[cur];
                }
            }
            mask>>=1;
        }
        return (res);
    }
};
BIT bit;
int a[MAX];
int p[MAX];
int n;
bool cmp(int x,int y) {
    return (a[x]<a[y]);
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,cmp);
    bit=BIT(n);
}
void process(void) {
    ll res=0;
    int tot=0;
    FOR(i,1,n) {
        int u=p[i];
        int t=bit.get(u);
        res+=1LL*(a[u]-tot)*max(0,n-i-1);
        tot=a[u];
        if (t>1 && t<n-i+1) res+=min(a[bit.find(t-1)],a[bit.find(t+1)])-tot;
        bit.remove(u);
    }
    cout<<res;
}
int main(void) {
    init();
    process();
    return 0;
}