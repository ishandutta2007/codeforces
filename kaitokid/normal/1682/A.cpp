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
        int n;
        string s;
        cin>>n>>s;
        int u=n/2;
        int ans=1;
        for(int i=u+1;i<n;i++)
        {
            if(s[i]==s[i-1])ans++;
            else break;
        }

        for(int i=u-1;i>=0;i--)
        {
            if(s[i]==s[i+1])ans++;
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}