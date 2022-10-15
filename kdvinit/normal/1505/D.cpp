/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y;
    cin>>x>>y;

    int freq[y+1]={0};
    while(x!=0)
    {
        int z = x%y;
        if(freq[z]==1) { cout<<"NO"<<endl; return; }
        freq[z]=1;
        x/=y;
    }
    cout<<"YES"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}