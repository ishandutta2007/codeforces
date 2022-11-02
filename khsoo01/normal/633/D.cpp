#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,a[1005],nxt[1000005],prv[1000005],ans=2,zerocnt;
ll stk[1000005],sz,st;
bool vis[1000005];
map<pair<ll,ll>,ll>where;
map<ll,ll>numcnt;

int main()
{
    ll i,j,tmp;
    bool flag;
    scanf("%lld",&n);
    for(i=0;i<n;i++) {
        scanf("%lld",&a[i]);
        numcnt[a[i]]++;
    }
    ans = max(ans,numcnt[0]);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            nxt[i*n+j] = -1;
            prv[i*n+j] = -1;
            where[{a[i],a[j]}] = i*n+j+1;
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(where[{a[j],a[i]+a[j]}]!=0) {
                nxt[i*n+j] = where[{a[j],a[i]+a[j]}]-1;
            }
            if(where[{a[j]-a[i],a[i]}]!=0) {
                prv[i*n+j] = where[{a[j]-a[i],a[i]}]-1;
            }
        }
    }
    for(i=0;i<n*n;i++) {
        tmp = i; flag = false;
        while(true) {
            if(vis[tmp]) {flag = true; break;}
            vis[tmp] = true;
            if(prv[tmp] == -1) break;
            tmp = prv[tmp];
        }
        if(flag) continue;
        numcnt[a[tmp/n]]--; sz=0; st=0;
        stk[sz++]=a[tmp/n];
        while(true) {
            vis[tmp] = true;
            numcnt[a[tmp%n]]--;
            stk[sz++] = a[tmp%n];
            if(numcnt[a[tmp%n]]<0) {
                while(numcnt[a[tmp%n]]<0) {
                    numcnt[stk[st]]++;
                    st++;
                }
            }
            ans = max(sz-st,ans);
            if(nxt[tmp] == -1) break;
            tmp = nxt[tmp];
        }
        while(st<sz) {
            numcnt[stk[st]]++;
            st++;
        }
    }
    printf("%lld",ans);
}