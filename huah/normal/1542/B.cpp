#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=2e5+5;
unordered_map<int,bool>vis;
bool judge(int n,int a,int b)
{
    if(n%b) return false;
    return true;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        if(a==1) printf((n-1)%b==0?"Yes\n":"No\n");
        else
        {
            ll x=1;
            bool flag=false;
            while(x<=n)
            {
                if(judge(n-x,a,b))
                {
                    flag=true;
                    break;
                }
                x*=a;
            }
            printf(flag?"Yes\n":"No\n");
        }
    }
}