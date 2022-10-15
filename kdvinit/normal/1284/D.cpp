/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int n;
int val[100001][4];

bool check_same_overlap(int sa,int ea,int sb,int eb)
{
    vector< vector<int> > time(2*n);

    for(int i=1;i<=n;i++)
    {
        time[i-1].push_back(val[i][sa]);
        time[i-1].push_back(0);
        time[i-1].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        time[i+n-1].push_back(val[i][ea]);
        time[i+n-1].push_back(1);
        time[i+n-1].push_back(i);
    }
    sort(time.begin(),time.end());

    multiset<int> strtb,ndb;

    for(int i=0;i<2*n;i++)
    {
        //cout<<i<<" "<<time[i][0]<<" "<<time[i][1]<<" "<<time[i][2]<<endl;
        int type=time[i][1];
        int index=time[i][2];

        if(type==0)
        {
            strtb.insert(val[index][sb]);
            ndb.insert(val[index][eb]);
            if(*strtb.rbegin()>*ndb.begin()) return false;
        }
        else
        {
            strtb.erase( strtb.find(val[index][sb]) );
            ndb.erase( ndb.find(val[index][eb]) );
        }
    }

    return true;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>val[i][0]>>val[i][1]>>val[i][2]>>val[i][3];

    bool ans=( check_same_overlap(0,1,2,3) && check_same_overlap(2,3,0,1));

    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}