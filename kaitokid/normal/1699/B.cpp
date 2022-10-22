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
        int n,m;
        cin>>n>>m;
        for(int j=0;j<n/2;j++)
        {
            for(int i=0;i<m/2;i++)
            {
                if((i+j)%2)cout<<"1 0 ";
                else cout<<"0 1 ";
            }
            cout<<endl;
            for(int i=0;i<m/2;i++)
            {
                if((i+j)%2)cout<<"0 1 ";
                else cout<<"1 0 ";
            }
            cout<<endl;
        }
    }
    return 0;
}