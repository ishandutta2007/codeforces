#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s[210];
int main()
{ios::sync_with_stdio(0);
int a,b,t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    if(s[0][1]==s[1][0])
    {
        int ans=0;
        if(s[n-1][n-2]==s[0][1])ans++;
        if(s[n-2][n-1]==s[0][1])ans++;
        cout<<ans<<endl;
        if(s[n-1][n-2]==s[0][1])cout<<n<<" "<<n-1<<endl;
        if(s[n-2][n-1]==s[0][1])cout<<n-1<<" "<<n<<endl;
     continue;
    }
    if(s[n-1][n-2]==s[n-2][n-1])
    {
        int ans=0;
        if(s[n-1][n-2]==s[0][1])ans++;
        if(s[n-2][n-1]==s[1][0])ans++;
        cout<<ans<<endl;
        if(s[n-1][n-2]==s[0][1])cout<<1<<" "<<2<<endl;
        if(s[n-2][n-1]==s[1][0])cout<<2<<" "<<1<<endl;
        continue;
    }
 cout<<2<<endl;
 if(s[0][1]!='0')cout<<1<<" "<<2<<endl;

 if(s[1][0]!='0')cout<<2<<" "<<1<<endl;
 if(s[n-1][n-2]!='1')cout<<n<<" "<<n-1<<endl;
 if(s[n-2][n-1]!='1')cout<<n-1<<" "<<n<<endl;
}
    return 0;
}