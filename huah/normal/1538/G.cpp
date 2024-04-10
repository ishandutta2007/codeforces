#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long ll;
//typedef __int128 ll;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=1e5+5,mod=998244353,G=3,Gi=332748118;
int t,x,y,a,b;
double cal(double g)
{
    return g+min((x-a*g)/b,(y-b*g)/a);
}
int ccal(int g)
{
    return g+min((x-a*g)/b,(y-b*g)/a);
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        scanf("%d%d%d%d",&x,&y,&a,&b);
        double l=0,r=min(x/a,y/b);
        while(r-l>30)
        {
            double ml=l+(r-l)/3,mr=r-(r-l)/3;
            if(cal(ml)>cal(mr)) r=mr;
            else l=ml;
        }
        int ans=0;
        for(int i=l;i<=r;i++) ans=max(ans,ccal(i));
        printf("%d\n",ans);
    }
}