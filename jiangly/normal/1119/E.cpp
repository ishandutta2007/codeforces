#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    LL ans=0;
    int res=0;
    for(int i=0;i<n;++i){
        int tmp=min(res,a[i]/2);
        ans+=tmp;
        res-=tmp;
        a[i]-=tmp*2;
        ans+=a[i]/3;
        res+=a[i]%3;
    }
    printf("%lld\n",ans);
    return 0;
}