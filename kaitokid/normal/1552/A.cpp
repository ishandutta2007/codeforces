#include <bits/stdc++.h>
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
        cin>>n;
        string s,t;
        cin>>s;
        t=s;
        sort(t.begin(),t.end());
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=t[i])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}