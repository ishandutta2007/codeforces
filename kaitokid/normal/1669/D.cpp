#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {

        int n;
        string s;
        cin>>n>>s;
        int i=0;
        bool ans=true;
        while(i<n)
        {
            if(s[i]=='W'){i++;continue;}

            bool bl=false;
            i++;
            while(i<n)
            {
                if(s[i]=='W')break;
                if(s[i]!=s[i-1])bl=true;
                i++;
            }
           if(bl==false)ans=false;
        }

        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;

}