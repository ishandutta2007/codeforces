#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[22][22];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int w,h;
        cin>>w>>h;
        for(int i=0;i<w;i++)
            for(int j=0;j<h;j++)ans[i][j]=0;
        cout<<1;
        for(int i=1;i<h-1;i++)
        {
            if((i==h-2)){cout<<0;continue;}
            if(i%2)cout<<0;
            else cout<<1;
        }
        cout<<1<<endl;
        for(int i=1;i<w-1;i++)
        {
            if(i%2){for(int j=0;j<h;j++)cout<<0;cout<<endl;continue;}
            if(i==w-2){for(int j=0;j<h;j++)cout<<0;cout<<endl;continue;}
            cout<<1;
            for(int j=1;j<h-1;j++)cout<<0;
            cout<<1<<endl;

        }
        cout<<1;
        for(int i=1;i<h-1;i++)
        {
            if((i==h-2)){cout<<0;continue;}
            if(i%2)cout<<0;
            else cout<<1;
        }
        cout<<1<<endl;

        }
    return 0;
}