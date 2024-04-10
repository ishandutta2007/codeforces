#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int fr[11],lst[11];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        for(int i=0;i<10;i++)fr[i]=lst[i]=-1;
        cin>>n>>k>>s;
        int ans=0;
        for(int i=0;i<n;i++){
                int u=s[i]-'0';
                ans+=u*11;
                lst[u]=i;
                if(fr[u]==-1)fr[u]=i;}
        int mx=0;
        for(int u=0;u<10;u++)
        {
            if(fr[u]==-1)continue;
            int g=k-fr[u];
            if(g<0)continue;
            for(int j=0;j<10;j++)
                {
                if(lst[j]==-1)continue;
                if(lst[j]==fr[u])continue;
                int f=n-1-lst[j];
                if(lst[j]<fr[u])f--;
                if(g>=f)mx=max(mx,u+10*j);

                }

        }

        cout<<ans-mx<<endl;

    }



    return 0;

}