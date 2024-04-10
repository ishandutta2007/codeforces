#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[300];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>s[i];
        bool bl=true;
        for(int i=0;i+1<n;i++)
            for(int j=0;j+1<m;j++)
        {
            int r=(s[i][j]-'0')+(s[i+1][j]-'0')+(s[i][j+1]-'0')+(s[i+1][j+1]-'0');
            if(r==3){bl=false;break;}
        }
        if(bl)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}