#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s,t;
int fr[26][26];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)fr[i][j]=0;
        cin>>n>>s>>t;
        for(int i=0;i<n;i++)
        {
            int u=s[i]-'a';
            int v=t[n-i-1]-'a';
            if(u<v)swap(u,v);
            fr[u][v]++;
        }
        bool ans=true;
        for(int i=0;i<26;i++)
            for(int j=0;j<i;j++)
              if(fr[i][j]%2)ans=false;
        if(!ans){cout<<"NO"<<endl;continue;}
        int u=0;
        for(int i=0;i<26;i++)
            if(fr[i][i]%2)u++;
        if(u>1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }


    return 0;
}