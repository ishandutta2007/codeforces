#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        int ans=n+10;
        for(char x='a';x<='z';x++)
        {
            int i=0,j=n-1;
            int res=0;
            while(j>i)
            {
                if(s[i]==s[j]){i++;j--;continue;}
                if(s[i]==x){res++;i++;continue;}
                if(s[j]==x){res++;j--;continue;}
                res=n+10;
                break;
            }
            ans=min(ans,res);
        }
        if(ans<=n)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}