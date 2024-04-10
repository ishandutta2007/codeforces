
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long double ld;
int x[200005],y[200005],a[200005],b[200005];
struct node
{
    long long a,b;
    friend bool operator <(node x,node y){return x.a==y.a?x.b<y.b:x.a<y.a;}
};

long long const inf=3e9;
map<node,int>mp1;
signed main()
{
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        mp1.clear();
        int n;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld%lld",&x[i],&y[i],&a[i],&b[i]);
            int t1=a[i]-x[i],t2=b[i]-y[i],g=__gcd(abs(t1),abs(t2));
            t1/=g,t2/=g;//t2/t1 [0,180)
            x[i]=t1,y[i]=t2;
            mp1[node{t1,t2}]++;
        }
        long long ans=0;
        for(int i=1;i<=n;i++) {
        	ans+=mp1[(node){-x[i],-y[i]}];
        	// cout<<mp1[(node){-x[i],-y[i]}]<<endl;
        }
        cout<<ans/2<<endl;
    }
    return 0;
}