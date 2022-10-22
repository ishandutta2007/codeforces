#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,r,b;
        cin>>n>>r>>b;
        int u=r/(b+1),v=r%(b+1);
        for(int i=1;i<=b;i++)
        {
            for(int j=0;j<u;j++)cout<<"R";
            if(i<=v)cout<<"R";
            cout<<"B";
        }
       for(int i=0;i<u;i++)cout<<"R";
       cout<<endl;
    }
    return 0;
}