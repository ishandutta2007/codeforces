#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[30];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    for(int i=0;i<28;i++)f[i]=0;
    string s;
    int p;
    cin>>s>>p;
    int sum=0;
    for(int i=0;i<s.size();i++)sum+=s[i]-'a'+1;
    string u=s;
    sort(u.begin(),u.end());
    int i=u.size();
    i--;
    while(sum>p)
    {
        sum-=u[i]-'a'+1;
        f[u[i]-'a']++;
        i--;
    }
    for(int i=0;i<s.size();i++)
    {
        if(f[s[i]-'a']){f[s[i]-'a']--;continue;}
        cout<<s[i];
    }
    cout<<endl;




}
return 0;
}