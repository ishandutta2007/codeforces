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
    reverse(s.begin(),s.end());
    int ans=1000;
    for(int i=0;i<s.size();i++)
        for(int j=i+1;j<s.size();j++)
        {
            int r=s[j]-'0';
            r*=10;
            r+=s[i]-'0';
            if(r%25==0)ans=min(ans,i+j-i-1);

        }
        cout<<ans<<endl;
    }
    return 0;
}