#include <bits/stdc++.h>
using namespace std;
bool fr[28];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        for(int i=0;i<26;i++)fr[i]=0;
        cin>>s;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            int u=s[i]-'a';
            if(fr[u]){

                ans--;
                for(int j=0;j<27;j++)fr[j]=0;
                continue;
            }
           fr[u]=true;
           ans++;
        }
       cout<<ans<<endl;
    }
    return 0;
}