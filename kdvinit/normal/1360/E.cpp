#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,cntr=0;
        cin>>n;
        int a[n+1][n+1];
        
        for(int i=0;i<=n;i++)
        {
            a[i][n]=1;
            a[n][i]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char x;
                cin>>x;
                if(x=='1') a[i][j]=1;
                else a[i][j]=0;
            }
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(a[i][j]==0) continue;
                if(a[i+1][j]==0 && a[i][j+1]==0) cntr++;
            }
        }
        
        if(cntr==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}