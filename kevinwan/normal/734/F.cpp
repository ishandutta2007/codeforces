#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=4e5+10;
ll a[mn],b[mn],c[mn],d[mn],e[mn],f[mn];
void die(){
    printf("-1");
    exit(0);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",b+i);
    for(int i=0;i<n;i++)scanf("%lld",c+i),d[i]=b[i]+c[i];
    ll s=0;
    for(int i=0;i<n;i++)s+=d[i];
    s/=2*n;
    for(int i=0;i<n;i++)a[i]=(d[i]-s)/n;
    for(int i=0;i<30;i++){
        int num=0;
        for(int j=0;j<n;j++)if((a[j]>>i)&1)num++;
        for(int j=0;j<n;j++){
            if((a[j]>>i)&1)e[j]+=((ll)num)<<i,f[j]+=((ll)n)<<i;
            else f[j]+=((ll)num)<<i;
        }
    }
    for(int i=0;i<n;i++)if(b[i]!=e[i]||c[i]!=f[i])die();
    for(int i=0;i<n;i++)printf("%lld ",a[i]);
}