#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=5e5+10;
vector<ll>v;
ll rv[mn],aa[mn],bb[mn];
int n;
int sc(ll x){
    int p=n;
    for(int i=0;i<n;i++)if(v[i]<=x){
        p=i;
        break;
    }
    v.insert(v.begin()+p,x);
    memset(bb,0,sizeof(bb));
    for(int i=0;i<=n;i++){
        rv[i]=min((ll)i,v[i]);
        if(min((ll)i,v[i]))bb[min((ll)i,v[i])-1]--;
    }
    for(int i=n-1;i>=0;i--)bb[i]+=bb[i+1];
    aa[0]=v[0];
    for(int i=1;i<=n;i++)aa[i]=aa[i-1]+v[i];
    bb[n]=rv[n];
    for(int i=n-1;i>=0;i--)bb[i]+=bb[i+1]+rv[i];
    int f=-1,su=0;
    for(int i=0;i<=n;i++){
        if(aa[i]>1LL*i*(i+1)+bb[i+1]){
            f=i;
            break;
        }
    }
    v.erase(v.begin()+p);
    if(f==-1)return 0;
    else if(f<p)return -1;
    else return 1;
}
int main(){
    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;i++)scanf("%lld",v.begin()+i);
    sort(v.begin(),v.end(),greater<ll>());
    bool p=0;
    for(int i=0;i<n;i++)p^=v[i]&1;
    int lo=-2+p;
    for(int i=1<<18;i>=2;i>>=1){
        if(lo+i>n)continue;
        if(sc(lo+i)==-1)lo+=i;
    }
    lo+=2;
    int hi=n-((n&1)^p)+2;
    for(int i=1<<18;i>=2;i>>=1){
        if(hi-i<0)continue;
        if(sc(hi-i)==1)hi-=i;
    }
    hi-=2;
    if(hi<lo)printf("-1");
    else for(int i=lo;i<=hi;i+=2)printf("%d ",i);
}