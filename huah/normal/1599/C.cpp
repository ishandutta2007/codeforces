#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
const int N=3e5+5;
typedef long long ll;
int n;
double p;
double cal(int n,int i)
{
    int a=n-i,b=i;
    ll way=1ll*n*(n-1)*(n-2)/6;
    ll w1=1ll*b*(b-1)*(b-2)/6;
    ll w2=1ll*b*(b-1)/2*a;
    ll w3=1ll*b*a*(a-1)/2;
    return 1.0*(w1+w2)/way+0.5*w3/way;
}
int main()
{
    scanf("%d%lf",&n,&p);
    int ans=0;
    for(int i=0;i<n;i++)
        if(cal(n,i)>=p) {ans=i;break;}
    printf("%d\n",ans);
}