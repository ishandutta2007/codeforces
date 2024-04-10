#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3e5+10;
int a[mn],hd[mn],num[mn];
map<int,int>m[mn];
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n,i;
        scanf("%d",&n);
        for(i=0;i<=n;i++)a[i]=0,hd[i]=0,num[i]=0,m[i].clear();
        for(i=0;i<n;i++)scanf("%d",a+i);
        hd[n]=n;
        for(i=n-1;i>=0;i--){
            hd[i]=i;
            if(m[hd[i+1]].find(a[i])!=m[hd[i+1]].end()) {
                int f = m[hd[i + 1]][a[i]];
                num[i] = num[f + 1] + 1;
                hd[i] = hd[f + 1];
            }
            m[hd[i]][a[i]]=i;
        }
        ll ans=0;
        for(i=0;i<n-1;i++)ans+=num[i];
        printf("%lld\n",ans);
    }
}