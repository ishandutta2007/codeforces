#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {


    string s;
    cin>>s;
    int ans=0,u=-1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1'&&u!=-1)ans+=i-u-1;
        if(s[i]=='1')u=i;
    }
    cout<<ans<<endl;
    }
    return 0;
}