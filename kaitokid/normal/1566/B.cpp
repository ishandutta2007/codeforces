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
        string s;
        cin>>s;
        int ans=0;
        if(s[0]=='0')ans=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='0' && s[i]!=s[i-1])ans++;
        }
        ans=min(ans,2);
        cout<<ans<<endl;
    }
    return 0;
}