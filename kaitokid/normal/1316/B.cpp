#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,t;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        string ans=s;
        int k=1;
        for(int i=1;i<n;i++)
        {
            string p="";
            for(int j=i;j<n;j++)p+=s[j];
            if((n-1-i)%2==1)for(int j=0;j<i;j++)p+=s[j];
            else for(int j=i-1;j>=0;j--)p+=s[j];
            if(p<ans){ans=p;k=i+1;}
        }
        cout<<ans<<endl<<k<<endl;
    }
    return 0;
}