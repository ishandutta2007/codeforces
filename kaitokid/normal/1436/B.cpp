#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ans[109][109];
int main()
{
    ios::sync_with_stdio(0);

    int t,n,m,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)ans[i][j]=0;
        for(int i=0;i<n;i++)
            ans[i][i]=ans[i][(i+1)%n]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
return 0;
}