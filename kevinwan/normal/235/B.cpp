#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mn=1e5+10;
ld p[mn],dp[mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i;
    cin>>n;
    ld c=0,l=0,sq=0,s=0;
    for(i=1;i<=n;i++)cin>>p[i];
    n++;
    c=1;
    for(i=1;i<=n;i++){
        dp[i]=(1-p[i])*(sq+s);
        s*=p[i];
        c*=p[i];
        l*=p[i];
        sq*=p[i];
        sq+=2*l+c;
        l+=c;
        c+=1-p[i];
        s+=dp[i];
    }
    printf("%.20Lf",dp[n]);
}