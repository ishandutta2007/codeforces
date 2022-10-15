/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int freq[10]={0};
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        if(x=='L')
        {
            int j=0;
            while(freq[j]==1) j++;
            freq[j]=1;
        }
        if(x=='R')
        {
            int j=9;
            while(freq[j]==1) j--;
            freq[j]=1;
        }
        int y = x-'0';
        freq[y]=0;
    }

    for(int i=0; i<=9; i++) cout<<freq[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}