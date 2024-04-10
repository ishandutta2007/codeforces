/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    vector<int> s;
    for(int i=1;i<=n;i++)
    {
        char x; cin>>x;
        int y=x-96;
        s.push_back(y);
    }

    int ans=0;
    int m=s.size();
    for(int i=26;i>0;i--)
    {
        for(int j=0;j<m;j++)
        {
            if(s[j]!=i) continue;

            int flag=0;
            if(j==0)
            {
                if(m>1 && s[1]==i-1) flag=1;
            }
            else if(j==m-1)
            {
                if(m>1 && s[m-2]==i-1) flag=1;
            }
            else
            {
                if( s[j-1]==(i-1) || s[j+1]==(i-1) ) flag=1;
            }

            if(flag==1)
            {
                s.erase(s.begin()+j);
                ans++;
                j--;
                if(j>=0) j--;
                m--;
            }
        }
    }

    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}