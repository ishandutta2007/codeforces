#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
int a[mn];
vector<int>g[mn];
int main()
{
    int n,m,i;
    scanf("%d",&n);
    m=n;
    for(i=1;i<=m;i++){
        scanf("%d",a+i);
        if(a[i]==a[i-1])i--,m--;
        else{
            g[a[i]].push_back(i);
        }
    }
    ll ans=0,cur=0;
    for(i=n;i;i--){
        for(int x:g[i]){
            cur+=n+1-i;
            if(a[x+1]>i)cur-=n+1-a[x+1];
            if(a[x-1]>i)cur-=n+1-a[x-1];
        }
        ans+=cur;
    }
    printf("%lld",ans);
}