#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mx[11]={};
        while(n--)
        {
            int b,d;
            cin>>b>>d;
            mx[d]=max(mx[d],b);
        }
        bool ok=true;
        for(int i=1;i<=10;i++)
            if(!mx[i])
                ok=false;
        if(ok)
            cout<<accumulate(mx+1,mx+11,0ll)<<"\n";
        else
            cout<<"MOREPROBLEMS\n";
    }
}