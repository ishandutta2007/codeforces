#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n,m,i,a[10005],l,r,x,lb=0,ub=0,d;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    cin>>a[i];
    while(m--)
    {
        cin>>l>>r>>x;
        d=a[x];
        lb=0;ub=-1;
        for(i=l;i<=r;++i)
        {
            if(a[i]<d) lb++;
            if(a[i]<=d) ub++;
        }
        if(x<=l+ub && x>=l+lb) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
    return 0;
}