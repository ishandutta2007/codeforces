#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
        string s="";
        for(int i=0;i<m;i++)s+='B';
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            x=min(x,m-x+1);
            if(s[x-1]=='B'){s[x-1]='A';continue;}
            s[m-x]='A';
        }
        cout<<s<<endl;

    }
    return 0;
}