#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1009][6];
int x,y,z,n;
void go(int u,int v)
{
    for(int i=0;i<n;i++)
    {
        if(a[i][u]&&a[i][v]){z++;continue;}

        if(a[i][u]){x++;continue;}

        if(a[i][v]){y++;continue;}

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<5;j++)cin>>a[i][j];
        bool ans=false;
        for(int i=0;i<5;i++)
            for(int j=i+1;j<5;j++)
            {
                x=y=z=0;
                go(i,j);
                if(x+y+z<n)continue;
                if(x>(n/2)|| y>(n/2))continue;
                ans=true;
                break;
            }
           if(ans)cout<<"YES"<<endl;
           else cout<<"NO"<<endl;

    }
    return 0;
}