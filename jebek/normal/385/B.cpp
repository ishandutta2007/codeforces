#include <iostream>
#include<string>

using namespace std;

string s;
long long ans;
bool dp[6000][6000];

int main()
{
    cin>>s;
    for(int i=3;i<s.size();i++)
        for(int j=i-3;j>-1;j--)
        {
            dp[i][j]=dp[i][j+1];
            if(s[j]=='b' && s[j+1]=='e' && s[j+2]=='a' && s[j+3]=='r')
                dp[i][j]=true;
            if(dp[i][j])
                ans++;
           // cout<<i<<" "<<j<<" "<<ans<<endl;
        }
    cout<<ans<<endl;
}