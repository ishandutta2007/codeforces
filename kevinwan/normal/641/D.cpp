#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+9;
const int mn=1e5+10;
double a[mn],b[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
    for(int i=1;i<=n;i++)cin>>b[i],b[i]+=b[i-1];
    for(int i=1;i<=n;i++){
        double p=a[i],s=b[i]+a[i];
        double d=sqrt(max(0.,s*s-4*p));
        a[i]=(s+d)/2;
        b[i]=(s-d)/2;
    }
    for(int i=1;i<=n;i++)printf("%.10lf ",a[i]-a[i-1]);
    printf("\n");
    for(int i=1;i<=n;i++)printf("%.10lf ",b[i]-b[i-1]);
}