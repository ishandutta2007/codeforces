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

    int b[n],win[n]={0};
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            cout<<"? "<<i<<" "<<j<<endl;
            char x;
            cin>>x;
            if(x=='>') win[i]++;
            else win[j]++;
        }
    }

    for(int i=1;i<n;i++)
    {
        b[win[i]+1]=i;
    }

    vector<int> c;
    for(int i=1;i<n;i++)
    {
        c.push_back(b[i]);
    }

    cout<<"? "<<n<<" "<<n+1<<endl;
    char zz; cin>>zz;
    int x,y;
    if(zz=='>') { x=n+1; y=n; }
    else { x=n; y=n+1; }

    int st;
    cout<<"? "<<c[0]<<" "<<x<<endl;
    cin>>zz;
    if(zz=='<')
    {
        c.erase(c.begin());
        st=1;
    }
    else
    {
        st=2;
    }

    for(int i=n+2;i<=2*n;i++)
    {
        if(st==1)
        {
            cout<<"? "<<c[n-3]<<" "<<i<<endl;
            cin>>zz;
            if(zz=='<')
            {
                c.push_back(i);
            }
            else
            {
                for(int j=0;j<n-2;j++)
                {
                    cout<<"? "<<c[j]<<" "<<i<<endl;
                    cin>>zz;
                    if(zz=='>')
                    {
                        c.insert(c.begin()+j,i);
                        break;
                    }
                }
            }
        }
        else
        {
            cout<<"? "<<y<<" "<<i<<endl;
            cin>>zz;
            if(zz=='>')
            {
                x=i;
            }
            else
            {
                x=y;
                y=i;
            }
        }

        cout<<"? "<<c[0]<<" "<<x<<endl;
        cin>>zz;
        if(zz=='<')
        {
            c.erase(c.begin());
            st=1;
        }
        else
        {
            st=2;
        }
    }

    cout<<"! "<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}