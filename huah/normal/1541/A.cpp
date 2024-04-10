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
        int n;scanf("%d",&n);
        if(n&1)
        {
            printf("3 1 2");
            for(int i=4;i<=n;i+=2) printf(" %d %d",i+1,i);
            printf("\n");
        }
        else for(int i=1;i<=n;i+=2) printf(i+1==n?"%d %d\n":"%d %d ",i+1,i);
    }
}