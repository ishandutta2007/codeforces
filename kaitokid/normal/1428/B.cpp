#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t,n;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>n>>s;
        bool b1=false,b2=false;
        for(int i=0;i<n;i++)
            if(s[i]=='>')b1=true;
        else if(s[i]=='<')b2=true;
        if(!b1||!b2){cout<<n<<endl;continue;}
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='-'||s[(i+1)%n]=='-')ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}