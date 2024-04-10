#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=1e6+10;
int ans[mn];
int main(){
    ll n,k,s;
    scanf("%lld%lld",&n,&k);
    s=n*(n+1)/2;
    if(k<n*(n+1)/2){
        printf("-1");
        return 0;
    }
    iota(ans,ans+mn,0);
    for(int i=1;i*2<=n;i++){
        int j=n+1-i;
        if(k-s>j-i)swap(ans[i],ans[j]),s+=j-i;
        else{
            swap(ans[i],ans[i+k-s]);
            s+=k-s;
            break;
        }
    }
    printf("%lld\n",s);
    for(int i=1;i<=n;i++)printf("%d ",i);
    printf("\n");
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}