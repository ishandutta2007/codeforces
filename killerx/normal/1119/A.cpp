#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,c[N],fst[N],lst[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",c+i);
    for(int i=1;i<=n;++i)if(!fst[c[i]])fst[c[i]]=i;
    for(int i=n;i>=1;--i)if(!lst[c[i]])lst[c[i]]=i;
    int mx=0,mx2=0;
    for(int i=1;i<=n;++i){
        if(lst[i]>mx2)mx2=lst[i];
        if(mx2>mx)swap(mx,mx2);
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        if(!fst[i])continue;
        if(i==c[mx])ans=max(ans,mx2-fst[i]);
        else ans=max(ans,mx-fst[i]);
    }
    printf("%d\n",ans);
    return 0;
}