#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=4e5+10;
ll mi[mn];
ll gcd(ll a,ll b){
    while(b)a%=b,swap(a,b);
    return a;
}
int dep[mn];
ll dis[mn];
bool vis[mn];
ll a,b,ans,lc=1,k;
int beg;
void step(){
    if(a==b){
        printf("%lld",ans);
        exit(0);
    }
    if(a-mi[a%lc]>=b){
        a-=mi[a%lc];
        ans++;
        return;
    }
    ll mo=1;
    for(int i=2;i<=k;i++)if(a-(a%i)>=b)mo=max(mo,a%i);
    a-=mo;
    ans++;
}
int main(){
    scanf("%lld%lld%lld",&a,&b,&k);
    for(int i=2;i<=k;i++)lc/=gcd(lc,i),lc*=i;
    for(int i=0;i<lc;i++){
        mi[i]=1;
        for(int j=2;j<=k;j++)mi[i]=max(mi[i],(ll)i%j);
    }
    int clen;
    ll cdis;
    for(int i=a%lc;1;){
        vis[i]=1;
        int j=(i-mi[i]+lc)%lc;
        if(vis[j]){
            clen=dep[i]+1-dep[j];
            cdis=dis[i]+mi[i]-dis[j];
            beg=i;
            break;
        }
        dep[j]=dep[i]+1;
        dis[j]=dis[i]+mi[i];
        i=j;
    }
    while(a%lc!=beg)step();
    ll num=(a-b)/cdis;
    a-=num*cdis;
    ans+=num*clen;
    while(1)step();
}