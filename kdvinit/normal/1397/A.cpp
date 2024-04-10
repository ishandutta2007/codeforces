/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    int freq[27]={0};
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int m=s.size();
        for(int j=0;j<m;j++)
        {
            freq[s[j]-96]++;
        }
    }

    for(int i=1;i<=26;i++)
    {
        if(freq[i]%n!=0) { cout<<"NO"<<endl; return; }
    }
    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}