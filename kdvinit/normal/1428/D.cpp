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

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int tar=0,b[2*n+1],c[2*n+1],cnt1=0,cnt2=0,cnt3=0,poss2[n+1]={0},poss3[n+1]={0},last1,last2,last3=-1,first=0;
    for(int i=n;i>0;i--)
    {
        if(a[i]==1)
        {
            first=1;
            cnt1++; cnt3++;
            tar++; b[tar]=i; c[tar]=n+1-cnt1;
            poss2[cnt1]=1;
            last1=i;
        }
        if(a[i]==2)
        {
            cnt2++; cnt3--;
            while(poss2[cnt2]==0 && cnt2<=n) cnt2++;
            if(cnt2>n) { cout<<-1<<endl; return; }
            tar++; b[tar]=i; c[tar]=n+1-cnt2;
            last2=i;
        }
        if(a[i]==3)
        {
            if(first==0) { cout<<-1<<endl; return; }
            if(cnt3==0 && last3!=last2) { last1=last2; last3=last2; }
            poss2[cnt1]=0;
            cnt1++;
            poss2[cnt1]=0;
            tar++; b[tar]=i; c[tar]=n+1-cnt1;
            tar++; b[tar]=last1; c[tar]=n+1-cnt1;
            last1=i;
        }
    }

    cout<<tar<<endl;
    for(int i=1;i<=tar;i++)
    {
        cout<<c[i]<<" "<<b[i]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}