#include<bits/stdc++.h>
using namespace std;
int ans[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        string s;
        cin>>n>>k>>s;
        int r=k;
        for(int i=0;i+1<n;i++)
        {
            ans[i]=0;
            if(k==0)
            {
                if(r%2){if(s[i]=='0')s[i]='1';else s[i]='0';}
                continue;
            }

            if(s[i]=='0' && ((r%2)==0)){s[i]='1';ans[i]=1;k--;continue;}

            if(s[i]=='1' && ((r%2)==1)){k--;ans[i]=1;continue;}
            s[i]='1';
        }
        ans[n-1]=k;
        if((r%2)!=(k%2))if(s[n-1]=='0')s[n-1]='1';else s[n-1]='0';
        cout<<s<<endl;
        for(int i=0;i<n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}