/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int x=2;
    while(1)
    {
        if(n%x!=0)
        {
            int y = x/2;
            int c = (n-y)/x;

            if(c>=y) cout<<x<<endl;
            else
            {
                int odd = (2*c+1);
                if(odd==1) cout<<-1<<endl;
                else cout<<odd<<endl;
            }
            return;
        }
        x*=2;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}