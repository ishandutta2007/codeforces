#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e5+10;
mt19937 rng(time(0));
vector<int> PRIMES={1000000007,
1000000009,
1000000021,
1000000033,
1000000087,
1000000093,
1000000097,
1000000103,
1000000123,
1000000181,
1000000207,
1000000223,
1000000241,
1000000271,
1000000289,
1000000297,
1000000321,
1000000349,
1000000363,
1000000403,
1000000409,
1000000411,
1000000427,
1000000433,
1000000439,
1000000447,
1000000453,
1000000459,
1000000483,
1000000513};
const ll mod=PRIMES[rng()%PRIMES.size()];
typedef pair<ll,ll>pll;
pll add(pll a,pll b){
    if(a.first>b.first)return a;
    else if(a.first<b.first)return b;
    else return {a.first,(a.second+b.second)%mod};
}
pll bit[mn];
void up(int a,pll b){for(;a<mn;a+=a&-a)bit[a]=add(bit[a],b);}
pll qu(int a){pll b={0,1};for(;a;a-=a&-a)b=add(b,bit[a]);return b;}
int a[mn];
pll l[mn],r[mn],res;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++){
        l[i]=qu(a[i]-1);
        l[i].first++;
        up(a[i],l[i]);
    }
    res=qu(mn-1);
    memset(bit,0,sizeof(bit));
    for(int i=n;i;i--){
        a[i]=mn-a[i];
        r[i]=qu(a[i]-1);
        r[i].first++;
        up(a[i],r[i]);
    }
    for(int i=1;i<=n;i++){
        if(l[i].first+r[i].first-1!=res.first)printf("1");
        else if(l[i].second*r[i].second%mod!=res.second)printf("2");
        else printf("3");
    }
}