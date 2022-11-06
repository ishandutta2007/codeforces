#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
ll n,a[N],ans=N;
ll myabs(ll a){if(a>>63)return -a;return a;}
int main(){
    cin>>n;if(n<3){cout<<0;return 0;}
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=-1;i<2;i++)for(int j=-1;j<2;j++){
        ll a1=a[1]+i,a2=a[2]+j,d=a2-a1,a0=a1-d,flag=1,tot=0;
        for(int k=3;k<=n;k++){tot+=myabs(a0+d*k-a[k]);if(1<myabs(a0+d*k-a[k]))flag=0;}
        if(flag)ans=min(ans,tot+abs(i)+abs(j));
    }
    if(ans==N)ans=-1;
    cout<<ans;
    return 0;
}