/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    vector< vector<int> > scan(m+1);

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        scan[i].push_back(y);
        scan[i].push_back(x);
    }
    sort(scan.begin()+1,scan.end());

    int lstout=0; // 0(lvl),1(out at 1),2(out at 2);
    scan[0].push_back(0);
    for(int i=1;i<=m;i++)
    {
        int diff=scan[i][0]-scan[i-1][0];
        int type=scan[i][1];

        if(diff==0)
        {
            if(type==lstout)
            {
                lstout=0;
                continue;
            }
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }

        diff%=2;
        if(lstout==0)
        {
            if(type==1)
            {
                lstout=2;
            }
            else
            {
                lstout=1;
            }
            continue;
        }
        if(lstout==1)
        {
            if(diff==0)
            {
                if(type==1)
                {
                    lstout=0;
                }
                else
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else
            {
                if(type==1)
                {
                    cout<<"NO"<<endl;
                    return;
                }
                else
                {
                    lstout=0;
                }
            }
            continue;
        }
        if(lstout==2)
        {
            if(diff==0)
            {
                if(type==1)
                {
                    cout<<"NO"<<endl;
                    return;
                }
                else
                {
                    lstout=0;
                }
            }
            else
            {
                if(type==1)
                {
                    lstout=0;
                }
                else
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
            continue;
        }
    }

    if(lstout!=0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}