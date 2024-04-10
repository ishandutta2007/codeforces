#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX   200200
using namespace std;
typedef long long ll;
const ll INF=(ll)1e14+1;
ll s[MAX];
ll v[MAX];
ll a[MAX];
int t[MAX];
int cs[MAX];
int ck[MAX];
int n;
ll q;
void init(void) {
    scanf("%d",&n);
    scanf("%I64d",&q);
    s[0]=0;
    v[1]=0;
    int i;
    for (i=1;i<=n;i=i+1) {
        scanf("%I64d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
}
void compress(const ll &k) {
    int i;
    //printf("Compress %I64d\n",k);
    for (i=0;i<=n;i=i+1) {
        v[2*i+1]=s[i];
        v[2*i+2]=s[i]+k;
    }
    sort(&v[1],&v[2*n+3]);
    //for (i=1;i<=2*n+2;i=i+1) printf("%I64d ",v[i]); printf("\n");
    for (i=0;i<=n;i=i+1) {
        cs[i]=lower_bound(&v[1],&v[2*n+3],s[i])-&v[0];
        ck[i]=lower_bound(&v[1],&v[2*n+3],s[i]+k)-&v[0];
    }
    //printf("Compress %I64d\n",k);
    //for (i=0;i<=n;i=i+1) printf("%d %d\n",cs[i],ck[i]);
}
void update(int v) {
    while (1<=v && v<=2*n+2) {
        t[v]++;
        v=v+(v&(-v));
    }
}
int sum(int v) {
    int res=0;
    while (1<=v && v<=2*n+2) {
        res+=t[v];
        v=v&(v-1);
    }
    return (res);
}
ll count(const ll &k) {
    memset(t,0,sizeof t);
    compress(k);
    int i;
    ll res=0;
    for (i=0;i<=n;i=i+1) {
        res+=sum(cs[i]);
        update(ck[i]);
        //printf("%d %I64d\n",i,res);
    }
    //printf("Count %I64d is %I64d\n",k,res);
    return (res);
}
void process(void) {
    ll l,m,r;
    l=-INF;r=INF;
    while (true) {
        if (l==r) {
            m=r;
            break;
        }
        if (r-l==1) {
            if (count(r)>=q) m=r;
            else m=l;
            break;
        }
        m=(l+r)/2;
        if (count(m)<q) r=m-1;
        else l=m;
    }
    printf("%I64d",m);
}
int main(void) {
    init();
    process();
    return 0;
}