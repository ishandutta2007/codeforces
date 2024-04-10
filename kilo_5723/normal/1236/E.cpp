#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
map<int,ll> cnt;
int a[maxn];
int main(){
    int i,n,m;
    ll sum1,sum2;
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++) scanf("%d",&a[i]);
    if (n==1){
        printf("%d\n",!m);
        return 0;
    }
    cnt.clear();
    for (i=1;i<=n;i++) cnt[i]=1;
    for (i=1;i<=m;i++){
        cnt[a[i]-i-1]+=cnt[a[i]-i];
        cnt[a[i]-i]=0;
    }
    sum1=0;
    for (auto nd:cnt){
        sum1+=min((nd.first+m+1),n)*nd.second;
     //   if (nd.second)
        //    cout<<min((nd.first+m+1),n)<<' '<<nd.second<<endl;
    }
    cnt.clear();
    for (i=1;i<=n;i++) cnt[i]=1;
    for (i=1;i<=m;i++){
        cnt[a[i]+i+1]+=cnt[a[i]+i];
        cnt[a[i]+i]=0;
    }
    sum2=0;
    for (auto nd:cnt)
        sum2+=max((nd.first-m-1),1)*nd.second;
    printf("%lld\n",sum1-sum2+n);
    return 0;
}