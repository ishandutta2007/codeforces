#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int d[26];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    d['S'-'A']=1;
    d['M'-'A']=2;
    d['L'-'A']=3;

    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        if(a==b)
        {
            cout<<"="<<endl;
            continue;
        }
        int u=a.size(),v=b.size();
        if(d[a[u-1]-'A']<d[b[v-1]-'A']){cout<<"<"<<endl;continue;}
        if(d[a[u-1]-'A']>d[b[v-1]-'A']){cout<<">"<<endl;continue;}
       if(a[u-1]=='S')
       {
           if(a<b)cout<<">"<<endl;
           else cout<<"<"<<endl;
           continue;
       }
        if(a>b)cout<<">"<<endl;
        else cout<<"<"<<endl;

    }
    return 0;
}