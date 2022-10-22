#include <iostream>

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        if(s[0]=='0'||s[n-1]=='0'){cout<<"NO\n";continue;}
        int u=0;
        for(int i=0;i<n;i++)u+=s[i]-'0';
        if(u%2){cout<<"NO\n";continue;}
        cout<<"YES\n";
        int d=0;
        u/=2;
        string ans[2]={"",""};
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                if(u){ans[0]+='(',ans[1]+='(';u--;}
                else {ans[0]+=')',ans[1]+=')';}
                continue;
            }
           ans[d]+='(';
           ans[d^1]+=')';
           d^=1;
        }
       cout<<ans[0]<<endl<<ans[1]<<endl;

    }
    return 0;
}