/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int q;
int query(int w)
{
    cout<<"? "<<w<<endl;
    cin>>q;
    return q;
}

void solve()
{
    int n;
    cin>>n;

    int l=0;
    int r=1e7;

    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(query(mid)==1) r=mid;
        else l=mid;
    }

    int sum = r-(n-1);
    int ans = r;

    for(int i=2; i<=n; i++)
    {
        int bst = sum+(n-i);
        for(int j=bst; j<ans; j++)
        {
            if(j%i!=0) continue;
            int y = j/i;
            if(query(y)==i) { ans=j; break; }
        }
    }

    cout<<"! "<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}