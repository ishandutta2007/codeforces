#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {

    int u=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
    {
        cin>>a[i][j];
        u+=a[i][j];
    }

    if(u==0){cout<<0<<endl;continue;}
    if(u==4){cout<<2<<endl;continue;}
    cout<<1<<endl;

    }

    return 0;
}