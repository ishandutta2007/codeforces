#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[30],n;
string s;
void ans(int x)
{
    cout<<char('a'+x);
    for(int i=0;i<26;i++)
    {
        if(i==x)continue;
        for(int j=0;j<fr[i];j++)cout<<char('a'+i);
    }
cout<<endl;
}
void go(int x)
{cout<<char('a'+x)<<char('a'+x);
    fr[x]-=2;
    string d="";
    for(int i=0;i<26;i++)
    {
        if(i==x)continue;
        for(int j=0;j<fr[i];j++)d+=char('a'+i);
    }
    int i=0;
   while(fr[x])
   {
       cout<<d[i++];
       cout<<char('a'+x);
       fr[x]--;
   }
   while(i<d.size())cout<<d[i++];
   cout<<endl;
}
void fuck()
{
    int x=s[0]-'a',y=s[n-1]-'a';
    cout<<char(x+'a');
    for(int i=0;i<fr[y];i++)cout<<char(y+'a');
    for(int i=1;i<fr[x];i++)cout<<char(x+'a');
    cout<<endl;
}
void khr(int x)
{
    cout<<char('a'+x);
    fr[x]--;
    int q;
    for(int i=x+1;i<26;i++)
    if(fr[i]){cout<<char(i+'a');fr[i]--;
    for(int j=i+1;j<26;j++){if(fr[j]){q=j;break;} }
    break;}
    fr[q]--;
    string d="";
    for(int i=0;i<26;i++)
    {
        if(i==x)continue;
        for(int j=0;j<fr[i];j++)d+=char('a'+i);
    }
    while(fr[x]){cout<<char(x+'a');fr[x]--;}
    cout<<char(q+'a');
    cout<<d;
cout<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        sort(s.begin(),s.end());
        for(int i=0;i<29;i++)fr[i]=0;
        int ds=0,sm=40;
        for(int i=0;i<s.size();i++)
        {
            sm=min(sm,s[i]-'a');
            fr[s[i]-'a']++;
            if(fr[s[i]-'a']==1)ds++;
        }
        if(ds==1){cout<<s<<endl;continue;}
        bool rs=false;
        for(int i=0;i<26;i++)
        {
            if(fr[i]==1){ans(i);rs=true;break;}
        }
        if(rs)continue;
        int z=fr[sm];
        n=s.size();
        if(z<=1+n/2){go(sm);continue;}
        if(ds==2){fuck();continue;}
        khr(sm);
        }
    return 0;
}