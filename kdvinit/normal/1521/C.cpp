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

    int ind1=0;

    for(int i=1; i<=n-1; i+=2)
    {
        int val;
        cout<<"? "<<2<<" "<<i<<" "<<i+1<<" "<<1<<endl;
        cin>>val;

        if(val>2) continue;

        if(val==1)
        {
            ind1=i;
            break;
        }

        if(val==2)
        {
            cout<<"? "<<2<<" "<<i+1<<" "<<i<<" "<<1<<endl;
            cin>>val;
            if(val==1) { ind1=i+1; break; }
        }
    }

    if(ind1==0) ind1=n;

    //cout<<ind1<<endl;

    int per[n+1];
    per[ind1]=1;

    for(int i=1; i<=n; i++)
    {
        if(i==ind1) continue;
        cout<<"? "<<1<<" "<<ind1<<" "<<i<<" "<<n-1<<endl;
        cin>>per[i];
    }

    cout<<"! ";
    for(int i=1; i<=n; i++) cout<<per[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}