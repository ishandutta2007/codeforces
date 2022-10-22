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
        string s;
        cin>>n>>s;
        int ans=0;
        for(int i=1;i<s.size();i++)
            if(s[i]=='0'&&s[i-1]=='0')ans+=2;
            else if(i+1<s.size() && s[i]=='1' && s[i-1]=='0' && s[i+1]=='0')ans++;
        cout<<ans<<endl;
    }
    return 0;
}