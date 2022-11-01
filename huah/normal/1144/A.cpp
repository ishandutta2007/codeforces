#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s;
        cin>>s;
        int a[26];
        bool flag=true;
        memset(a,0,sizeof(a));
        for(int i=0;i<s.size();i++)
            if(++a[s[i]-'a']>1) {flag=false;break;}
        vector<int>v;
        for(int i=0;i<26;i++)
            if(a[i]) v.push_back(i);
        for(int i=0;i<v.size()-1;i++)
            if(v[i]!=v[i+1]-1) flag=false;
        printf(flag?"YES\n":"NO\n");
    }
}