#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[27][27];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {

        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)fr[i][j]=0;
        int n;
        cin>>n;
        string s;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            int u=s[0]-'a',v=s[1]-'a';
            for(int i=0;i<26;i++)
                if(i!=u)ans+=fr[i][v];
            for(int i=0;i<26;i++)
                if(i!=v)ans+=fr[u][i];
            fr[u][v]++;

        }
        cout<<ans<<endl;
    }

    return 0;

}