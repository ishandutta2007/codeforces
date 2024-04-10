#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m;
    cin >> n >> m;
    
    int socks_left=n,ans;
    for(int i=1;1;i++)
    {
        socks_left--;
        if(socks_left<0)
        {
            ans=i-1;
            break;
        }
        
        if(i%m==0) socks_left++;
    }
    cout<<ans<<endl;
}

int main()
{
    solve();
    return 0;
}