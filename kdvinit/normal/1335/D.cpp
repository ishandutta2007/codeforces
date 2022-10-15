/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[10][10];

void change(int i,int j)
{
    int x=a[i][j];
    x=(x%9)+1;
    a[i][j]=x;
}

void solve()
{

    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            char x; cin>>x;
            a[i][j]=x-48;
        }
    }

    change(1,1);
    change(2,4);
    change(3,7);
    change(4,2);
    change(5,5);
    change(6,8);
    change(7,3);
    change(8,6);
    change(9,9);

    //cout<<endl;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++) cout<<a[i][j];
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}