/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n; cin>>n;
    char c; cin>>c;

    vector<int> num;
    int freq[n+1]={0};

    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        if(x!=c) { freq[i]=1; num.push_back(i); }
    }

    int m = num.size();

    if(m==0)
    {
        cout<<0<<endl<<endl;
        return;
    }

    if(m==1)
    {
        if(freq[n]==1) cout<<1<<endl<<n-1<<endl;
        else cout<<1<<endl<<n<<endl;
        return;
    }

    if(freq[n]==0)
    {
        cout<<1<<endl<<n<<endl;
        return;
    }

    int pos[n+1];
    for(int i=1; i<=n; i++) pos[i]=1;

    for(int x: num)
    {
        for(int i=1; i*i<=x; i++)
        {
            if(x%i!=0) continue;
            int f1 = i;
            int f2 = x/i;
            pos[f1]=0;
            pos[f2]=0;
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(pos[i]==1)
        {
            cout<<1<<endl<<i<<endl;
            return;
        }
    }

    cout<<2<<endl;
    cout<<n-1<<" "<<n<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}