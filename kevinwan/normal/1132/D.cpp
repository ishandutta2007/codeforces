#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=2e5+10;
ll A[mn],a[mn],b[mn];
int n,k;
vector<int>ded[mn];
bool solve(ll x){
    memcpy(a,A,sizeof(a));
    for(int i=0;i<n;i++)ded[min((ll)k,a[i]/b[i])].push_back(i);
    int num=0;
    for(int i=0;i<k;i++){
        if(num>i)return 0;
        for(int j=0;j<ded[i].size();j++){
            if(num>i)return 0;
            int h=ded[i][j];
            a[h]+=x;
            ded[min((ll)k,a[h]/b[h])].push_back(h);
            num++;
        }
    }
    if(num>k)return 0;
    return 1;
}
int main(){
    scanf("%d%d",&n,&k);
    k--;
    for(int i=0;i<n;i++)scanf("%lld",A+i);
    for(int i=0;i<n;i++)scanf("%lld",b+i);
    ll cur=-1;
    for(ll i=1LL<<40;i;i>>=1){
        if(!solve(cur+i))cur+=i;
        for(int j=0;j<=k;j++)ded[j].clear();
    }
    if(cur<2e12)printf("%lld",cur+1);
    else printf("-1");
}