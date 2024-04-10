#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,x;
string s;
char w[100009],d[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>s>>x;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            w[i]='1';
            if(i+x<n&&(s[i+x]=='0'))w[i]='0';
            if(i-x>=0&&(s[i-x]=='0'))w[i]='0';
        }
        bool bl=false;
        for(int i=0;i<n;i++)
        {
            d[i]='0';
            if(i-x>=0&&w[i-x]=='1')d[i]='1';
            if(i+x<n&&w[i+x]=='1')d[i]='1';
            if(d[i]!=s[i]){bl=true;break;}
        }
        if(bl){cout<<-1<<endl;continue;}
        for(int i=0;i<n;i++)cout<<w[i];
        cout<<endl;
    }
    return 0;
}