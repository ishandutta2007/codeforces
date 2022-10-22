#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000000];
int main(){
    int n,i,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%lld",a+i);
    sort(a,a+n);
    ll cum=0;
    for(i=0;i<n;i++){
        if(a[i]>=cum)ans++,cum+=a[i];
    }
    printf("%d",ans);
}