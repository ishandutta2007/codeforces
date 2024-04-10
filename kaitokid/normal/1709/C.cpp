#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
 int t;
 cin>>t;
 while(t--)
 {
     cin>>s;
     int n=s.size();
     int p=0,q=0;
     vector<int>g;
     for(int i=0;i<s.size();i++)
       {
           if(s[i]=='(')p++;
            if(s[i]==')')q++;
            if(s[i]=='?')g.push_back(i);
       }
       int r=(n/2)-p,f=(n/2)-q;
       if((r==0)||(f==0)){cout<<"YES"<<endl;continue;}
       for(int i=0;i<r;i++)s[g[i]]='(';
       for(int i=r;i<g.size();i++)s[g[i]]=')';
       swap(s[g[r-1]],s[g[r]]);
       bool ans=false;
       int u=0;
       for(int i=0;i<n;i++)
       {
           if(s[i]=='(')u++;else u--;
           if(u<0){ans=true;break;}
       }
       if(ans)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
 }

    return 0;
}