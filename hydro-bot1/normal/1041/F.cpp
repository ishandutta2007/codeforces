// Hydro submission #61db7fd63aa9cfeed585311c@1641775063008
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,_,m,a[N],b[N],ans;
map<int,int> mp;
int main(){
    scanf("%d%d",&n,&_);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mp[a[i]]++;
        ans=max(ans,mp[a[i]]);
    }
    scanf("%d%d",&m,&_);
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        mp[b[i]]++;
        ans=max(ans,mp[b[i]]);
    }
    for(int p=1;p<=1e9;p<<=1){
        mp.clear();
        for(int i=1;i<=n;i++){
            mp[a[i]%(p*2)]++;
            ans=max(ans,mp[a[i]%(2*p)]);
        }
        for(int i=1;i<=m;i++){
            mp[(b[i]+p)%(p*2)]++;
            ans=max(ans,mp[(b[i]+p)%(2*p)]);
        }
    }
    printf("%d",ans);
}