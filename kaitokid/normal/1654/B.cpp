#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int last[40];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{
string s;
 cin>>s;
 int n=s.size();
 for(int i=0;i<n;i++)last[s[i]-'a']=i;
 int u=0;
 for(int i=0;i<n;i++)
 if(last[s[i]-'a']==i){u=i;break;}
 for(int i=u;i<n;i++)cout<<s[i];
 cout<<endl;
}
}