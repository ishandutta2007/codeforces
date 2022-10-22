#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[509][509],n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=1;j<n;j++)ans[i][j]=(ans[i][j-1]+i)%n;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        int u=(x-ans[i][i]+n)%n;
        for(int j=0;j<n;j++)ans[i][j]=(ans[i][j]+u)%n;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cout<<ans[i][j]<<" ";
        cout<<endl;

    }


    return 0;
}