#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
const int m=100007;
typedef pair<int,int> ii;
class IT {
    private:
    vector<int> sum,cnt;
    int n;
    void assign(int i,int l,int r,int u,int x) {
        if (l==r) {
            sum[i]=x;
            cnt[i]=1;
            return;
        }
        int m=(l+r)>>1;
        if (u>m) assign(2*i+1,m+1,r,u,x);
        else assign(2*i,l,m,u,x);
        sum[i]=sum[2*i]+sum[2*i+1];
        cnt[i]=cnt[2*i]+cnt[2*i+1];
    }
    void remove(int i,int l,int r,int u) {
        if (l==r) {
            sum[i]=0;
            cnt[i]=0;
            return;
        }
        int m=(l+r)>>1;
        if (u>m) remove(2*i+1,m+1,r,u);
        else remove(2*i,l,m,u);
        sum[i]=sum[2*i]+sum[2*i+1];
        cnt[i]=cnt[2*i]+cnt[2*i+1];
    }
    public:
    IT() {
        n=0;
    }
    IT(int n) {
        this->n=n;
        sum.assign(4*n+7,0);
        cnt.assign(4*n+7,0);
    }
    void assign(int u,int x) {
        assign(1,1,n,u,x);
    }
    void remove(int u) {
        remove(1,1,n,u);
    }
    int getsum(int x) {
        if (x<=0) return (0);
        int i=1;
        int l=1;
        int r=n;
        int ret=0;
        while (true) {
            if (l==r) return (ret+sum[i]);
            int m=(l+r)>>1;
            if (cnt[2*i]<x) {
                ret+=sum[2*i];
                x-=cnt[2*i];
                i=2*i+1;
                l=m+1;
            }
            else {
                i=2*i;
                r=m;
            }
        }
    }
};
vector<ii> a[MAX];
int p[MAX],id[MAX];
ii b[MAX];
int n;
IT myit;
bool cmp(const int &x,const int &y) {
    return (a[x].size()>a[y].size());
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&b[i].se,&b[i].fi);
    sort(b+1,b+n+1);
    FOR(i,1,n) a[b[i].se].push_back(ii(b[i].fi,i));
    FOR(i,1,m) p[i]=i;
    sort(p+1,p+m+1,cmp);
}
void process(void) {
    int res=INF;
    int tmp=0;
    int buy=0;
    myit=IT(n);
    FOR(i,1,n) myit.assign(i,b[i].fi);
    FORD(i,n,1) {
        FOR(k,1,m) {
            int j=p[k];
            if (a[j].size()>=i) {
                //printf("BUY %d of %d\n",a[j][id[j]].se,j);
                tmp+=a[j][id[j]].fi;
                myit.remove(a[j][id[j]].se);
                id[j]++;
                buy++;
            }
            else break;
        }
        //printf("AT %d buy %d with %d\n",i,buy,tmp);
        //printf("NEED %d with %d\n",i-buy,myit.getsum(i-buy));
        res=min(res,tmp+myit.getsum(i-buy));
    }
    printf("%d",res);
}
int main(void) {
    init();
    process();
}