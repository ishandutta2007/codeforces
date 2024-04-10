#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=2e5+5;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        int a=0,b=0;
        n<<=1;
        while(n--)
        {
            int x;scanf("%d",&x);
            if(x&1) a++;
            else b++;
        }
        printf(a==b?"Yes\n":"No\n");
    }
}