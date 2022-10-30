// Hydro submission #619465b401410992b687a649@1637115316786
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(T) scanf("%d",&T)
#define scc(x,y) scanf("%d %d",&x,&y)
#define pr(T) printf("%d\n",T)
#define inf 0x3f3f3f3f

int main()
{
    // cout<<0LL<<endl; 0
    int T;
    sc(T);
    while(T--)
    {
        int n;
        sc(n);
        ll w=0;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            w=max(0LL,w+x);
        }
        cout<<w<<endl;
    }
    return 0;
}