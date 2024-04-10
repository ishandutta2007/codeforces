#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=1e2+10;
int a[mn],u[mn],l[mn];
set<pair<ll,int>>hail;
int n;
int num[101];
ll mult=1318468947;
ll hsh(int a[]){
    ll ret=0;
    for(int i=0;i<n;i++){
        ret=ret*mult+a[i]-a[0];
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i),u[i]=a[i]>>16,l[i]=a[i]&((1<<16)-1),u[i]^=(1<<15)-1;
    for(int i=0;i<1<<16;i++){
        for(int j=0;j<n;j++)num[j]=__builtin_popcount(l[j]^i);
        hail.insert({hsh(num),i});
    }
    for(int i=0;i<1<<15;i++){
        for(int j=0;j<n;j++)num[j]=__builtin_popcount(u[j]^i);
        ll ref=hsh(num);
        auto it=hail.lower_bound({ref,0});
        if(it!=hail.end()&&it->first==ref){
            int ans=(i<<16)+it->second;
            printf("%d",ans);
            return 0;
        }
    }
    printf("-1");
}