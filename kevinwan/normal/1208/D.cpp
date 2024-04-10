#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
ll bit[mn];
void up(int a,ll b){for(;a<mn;a+=a&-a)bit[a]+=b;}
ll qu(int a){ll b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
ll s[mn];
int ans[mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,j,k,l;
    cin>>n;
    for(i=0;i<n;i++)cin>>s[i];
    for(i=1;i<=n;i++)up(i,i);
    for(i=n-1;i>=0;i--){
        int cur=0;
        ll cum=0;
        for(j=1<<17;j;j>>=1){
            if(cur+j>n)continue;
            if(bit[cur+j]+cum<=s[i])cum+=bit[cur+j],cur+=j;
        }
        cur++;
        ans[i]=cur;
        up(cur,-cur);
    }
    for(i=0;i<n;i++)printf("%d ",ans[i]);
}