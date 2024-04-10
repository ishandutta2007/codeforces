#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=3e5+10;
ll p[mn];
int x,y,a,b;
ll k;
ll check(int n){
    int ab=n/(1LL*a/__gcd(a,b)*b),aa=n/a-ab,bb=n/b-ab;
    int cur=0;
    ll ret=0;
    for(int i=0;i<ab;i++)ret+=(x+y)*p[cur++];
    for(int i=0;i<aa;i++)ret+=(x)*p[cur++];
    for(int i=0;i<bb;i++)ret+=(y)*p[cur++];
    return ret;
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--){
        int n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%lld",p+i),p[i]/=100;
        scanf("%d%d%d%d%lld",&x,&a,&y,&b,&k);
        sort(p,p+n,greater<ll>());
        int cur=-1;
        if(x<y)swap(x,y),swap(a,b);
        for(i=1<<18;i;i>>=1){
            if(cur+i>n)continue;
            if(check(cur+i)<k)cur+=i;
        }
        if(cur==n)printf("-1\n");
        else printf("%d\n",cur+1);
    }
}