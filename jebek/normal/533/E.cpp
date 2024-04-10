#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

string s,t;
int n;
long long ans;

int main()
{
    cin>>n>>s>>t;
    if(s==t)
    {
        ans=26;
        for(int i=1;i<n;i++)
            ans=(ans+25);
        cout<<ans<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
        if(s[i]!=t[i])
        {
            int j=i;
            while(j<n-1 && s[j]==t[j+1])
                j++;
            j++;
            while(j<n && s[j]==t[j])
                j++;
            if(j==n)
                ans+=1;
            j=i;
            while(j<n-1 && s[j+1]==t[j])
                j++;
            j++;
            while(j<n && s[j]==t[j])
                j++;
            if(j==n)
                ans+=1;
            cout<<ans<<endl;
            break;
        }
}