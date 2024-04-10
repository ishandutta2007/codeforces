#include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
ii a[MAX];
ll s[MAX];
int n,k;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        int v;
        scanf("%d",&v);
        a[i]=ii(v,i);
    }
    sort(a+1,a+n+1);
    FOR(i,1,n) s[i]=s[i-1]+a[i].fi;
    scanf("%d",&k);
}
void process(void) {
    ll res=0LL;
    int pos=1;
    FOR(i,1,k) res+=1LL*a[i].fi*(2*i-k-1);
    ll sum=res;
    FOR(i,2,n-k+1) {
        sum+=1LL*a[i+k-1].fi*(k-1);
        sum-=1LL*a[i-1].fi*(1-k);
        sum-=2*(s[i+k-2]-s[i-1]);
        if (res>sum) {
            res=sum;
            pos=i;
        }
        //printf("%d %d\n",i,sum);
    }
    FOR(i,1,k) printf("%d ",a[pos-1+i].se);
}
int main(void) {
    init();
    process();
    return 0;
}