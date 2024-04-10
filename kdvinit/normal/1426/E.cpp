/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int infy=1e10;

void sub(int a[],int b[],int x,int y)
{
    int temp=min(a[x],b[y]);
    a[x]-=temp;
    b[y]-=temp;
}

void solve()
{
    int n;
    cin>>n;

    int a[4],b[4];
    cin>>a[1]>>a[2]>>a[3];
    cin>>b[1]>>b[2]>>b[3];

    int amax=0;
    amax+=min(a[1],b[2]);
    amax+=min(a[2],b[3]);
    amax+=min(a[3],b[1]);

    int amin1,amin2,amin3;

    while(1)
    {
        int ta[4],tb[4];
        ta[1]=a[1];ta[2]=a[2];ta[3]=a[3];tb[1]=b[1];tb[2]=b[2];tb[3]=b[3];

        sub(ta,tb,2,1);
        sub(ta,tb,2,2);
        sub(ta,tb,3,2);
        sub(ta,tb,3,3);
        sub(ta,tb,1,1);
        sub(ta,tb,1,3);

        amin1=ta[1]+ta[2]+ta[3];
        break;
    }

    while(1)
    {
        int ta[4],tb[4];
        ta[1]=a[1];ta[2]=a[2];ta[3]=a[3];tb[1]=b[1];tb[2]=b[2];tb[3]=b[3];

        sub(ta,tb,3,2);
        sub(ta,tb,3,3);
        sub(ta,tb,1,3);
        sub(ta,tb,1,1);
        sub(ta,tb,2,2);
        sub(ta,tb,2,1);

        amin2=ta[1]+ta[2]+ta[3];
        break;
    }

    while(1)
    {
        int ta[4],tb[4];
        ta[1]=a[1];ta[2]=a[2];ta[3]=a[3];tb[1]=b[1];tb[2]=b[2];tb[3]=b[3];

        sub(ta,tb,1,3);
        sub(ta,tb,1,1);
        sub(ta,tb,2,1);
        sub(ta,tb,2,2);
        sub(ta,tb,3,3);
        sub(ta,tb,3,2);

        amin3=ta[1]+ta[2]+ta[3];
        break;
    }

    int amin=min(amin1,amin2);
    amin=min(amin,amin3);

    cout<<amin<<" "<<amax<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}