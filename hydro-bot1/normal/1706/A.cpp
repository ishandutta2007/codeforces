// Hydro submission #62d7a7f1cf4d7374b3eec72a@1658300402106
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,a,i;
    cin>>t;
    while(t--)
    {
        string s="";
        cin>>n>>m;
        for(i=0;i<m;i++)
        s+='B';
        for(i=0;i<n;i++)
        {
            cin>>a;
            pair<int,int> b=minmax(a-1,m-a);
            if(s[b.first]=='B')
            s[b.first]='A';
            else s[b.second]='A';
        }
        cout<<s<<endl;
    }
    return 0;    
}