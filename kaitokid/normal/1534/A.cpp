#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[55];
int n,m;
bool ch()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        if((((i+j)%2)==0)&&s[i][j]=='W')return false;
        if((((i+j)%2)==1)&&s[i][j]=='R')return false;
    }
        return true;
}
bool cc()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        if((((i+j)%2)==0)&&s[i][j]=='R')return false;
        if((((i+j)%2)==1)&&s[i][j]=='W')return false;
    }
        return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>s[i];
        if(ch())
        {
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    if(((i+j)%2)==0)cout<<"R";else cout<<"W";
                cout<<endl;
            }
            continue;
        }
        if(cc())
        {
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    if((i+j)%2==0)cout<<"W";else cout<<"R";
                cout<<endl;
            }
            continue;
        }
        cout<<"NO"<<endl;


    }
    return 0;
}