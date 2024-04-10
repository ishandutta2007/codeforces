#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int r[40];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string t,s;
        cin>>t>>s;
        for(int i=0;i<t.size();i++)r[t[i]-'a']=i;
        int ans=0;
        for(int i=1;i<s.size();i++)
            ans+=abs(r[s[i]-'a']-r[s[i-1]-'a']);
        cout<<ans<<endl;

    }
    return 0;
}