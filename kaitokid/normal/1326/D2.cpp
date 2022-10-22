#include <bits/stdc++.h>

using namespace std;
int d[1000008];
string go(string s)
{
    string t=s;
    reverse(t.begin(),t.end());
int i=0,j=-1;
d[0]=-1;
while(i<s.size())
{
    while(j>-1&&s[i]!=s[j])j=d[j];
    i++;
    j++;
    d[i]=j;
}
i=0,j=0;
int ans1=0;
while(i<t.size())
{
    while(j!=-1&&t[i]!=s[j])j=d[j];
    i++;
    j++;
    if(t.size()-i<=j){ans1=t.size()-i+j;break;}
    if(j==s.size())j=d[j];
}
i=0,j=-1;
d[0]=-1;
while(i<t.size())
{
    while(j>-1&&t[i]!=t[j])j=d[j];
    i++;
    j++;
    d[i]=j;
}
i=0,j=0;
int ans2=0;
while(i<s.size())
{
    while(j!=-1&&s[i]!=t[j])j=d[j];
    i++;
    j++;
    if(s.size()-i<=j){ans2=s.size()-i+j;break;}
    if(j==t.size())j=d[j];
}
string res="";
if(ans1>=ans2)
{for(int i=0;i<ans1;i++)res+=s[i];
return res;}
for(int i=s.size()-ans2;i<s.size();i++)
    res+=s[i];
return res;
}
int q;
string s;
int main()
{
ios::sync_with_stdio(0);
cin>>q;
while(q--)
{
    cin>>s;
    int l=0,r=s.size()-1;
    while(r>l&&s[l]==s[r]){l++;r--;}
    if(r<=l){cout<<s<<endl;continue;}
    string t="";
    for(int i=l;i<=r;i++)t+=s[i];
    for(int i=0;i<l;i++)cout<<s[i];
    cout<<go(t);
    for(int i=r+1;i<s.size();i++)cout<<s[i];
    cout<<endl;
}
    return 0;
}