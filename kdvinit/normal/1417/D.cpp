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

    int a[n+1],sum=0;
    for(int i=1;i<=n;i++) { cin>>a[i]; sum+=a[i]; }

    if(sum%n!=0) { cout<<-1<<endl; return; }
    sum/=n;

    vector<int> l,r,val;

    for(int i=2;i<=n;i++)
    {
        int y=(a[i]+i-1)/i;
        y*=i;
        y-=a[i];
        if(y<=a[1])
        {
            l.push_back(1);
            r.push_back(i);
            val.push_back(y);
            a[1]-=(y);
            a[i]+=(y);
            y=a[i]/i;
            l.push_back(i);
            r.push_back(1);
            val.push_back(y);
            a[1]+=i*y;
            a[i]-=i*y;
            continue;
        }
        if(a[i]<i) continue;
        int x=a[i]/i;
        l.push_back(i);
        r.push_back(1);
        val.push_back(x);
        a[i]-=(i*x);
        a[1]+=(i*x);
        y=(a[i]+i-1)/i;
        y*=i;
        y-=a[i];
        if(y<=a[1])
        {
            l.push_back(1);
            r.push_back(i);
            val.push_back(y);
            a[1]-=(y);
            a[i]+=(y);
            y=a[i]/i;
            l.push_back(i);
            r.push_back(1);
            val.push_back(y);
            a[1]+=i*y;
            a[i]-=i*y;
            continue;
        }
    }

    while(1)
    {
        int flag_nomove_poss=1,flag_all_less=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==0) continue;
            if(a[i]<=sum) continue;
            flag_all_less=0;
            int y=i-a[i];
            if(y>a[1]) continue;
            flag_nomove_poss=0;
            l.push_back(1);
            r.push_back(i);
            val.push_back(y);
            a[1]-=(y);
            a[i]+=(y);
            l.push_back(i);
            r.push_back(1);
            val.push_back(1);
            a[1]+=i;
            a[i]-=i;
        }
        if(flag_all_less) break;
        if(flag_nomove_poss) { cout<<-1<<endl; return; }
    }

    for(int i=2;i<=n;i++)
    {
        int x=sum-a[i];
        l.push_back(1);
        r.push_back(i);
        val.push_back(x);
        a[i]+=x;
        a[1]-=x;
    }

    cout<<l.size()<<endl;
    for(int i=0;i<l.size();i++)
    {
        cout<<l[i]<<" "<<r[i]<<" "<<val[i]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}