#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,mx1,mx2,x;
        cin>>n>>mx1;
        for(int i=1;i<n;i++)
        {
            cin>>x;
            mx1=max(mx1,x);
        }
        cin>>m>>mx2;
        for(int i=1;i<m;i++)
        {
            cin>>x;
            mx2=max(mx2,x);
        }
        if(mx1>=mx2)
        cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
        if(mx2>=mx1)
         cout<<"Bob"<<endl;
            else
        cout<<"Alice"<<endl;

    }
    return 0;
}