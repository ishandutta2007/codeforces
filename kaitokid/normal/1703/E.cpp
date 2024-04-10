#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[109][109];
bool vis[109][109];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){cin>>a[i][j];vis[i][j]=0;}
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
        {
            if(vis[i][j])continue;
            int u=0,v=0;
            if(!vis[i][j]){vis[i][j]=true;if(a[i][j]=='0')u++;else v++;}
            if(!vis[j][n-i-1]){vis[j][n-i-1]=true;if(a[j][n-i-1]=='0')u++;else v++;}
            if(!vis[n-i-1][n-j-1]){vis[n-i-1][n-j-1]=true;if(a[n-i-1][n-j-1]=='0')u++;else v++;}
            if(!vis[n-j-1][i]){vis[n-j-1][i]=true;if(a[n-j-1][i]=='0')u++;else v++;}

            ans+=min(u,v);
        }
        cout<<ans<<endl;

    }


    return 0;

}