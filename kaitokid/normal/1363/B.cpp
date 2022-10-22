#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t,n,x;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int a[2]={0,0},b[2]={0,0};
        for(int i=0;i<s.size();i++)
            a[s[i]-'0']++;
            int ans=1e9;
        for(int i=0;i<s.size();i++)
        {

            int u=b[1];
            b[s[i]-'0']++;
            int v=a[0]-b[0];
            ans=min(ans,u+v);
        }
        b[0]=b[1]=0;
        for(int i=0;i<s.size();i++)
        {

            int u=b[0];
            b[s[i]-'0']++;
            int v=a[1]-b[1];
            ans=min(ans,u+v);
        }
        cout<<ans<<endl;
    }
    return 0;
}