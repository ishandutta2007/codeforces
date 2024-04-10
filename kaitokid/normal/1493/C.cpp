#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int k,need,fr[30];
void rem(int x)
{
    need-=(k-fr[x])%k;
    fr[x]=(fr[x]+k-1)%k;
    need+=(k-fr[x])%k;

}
void add(int x)
{
    need-=(k-fr[x])%k;
    fr[x]=(fr[x]+1)%k;
    need+=(k-fr[x])%k;

}
void go()
{
    for(int i='a';i<='z';i++)
    {
        for(int j=0;j<(k-fr[i-'a'])%k;j++)cout<<char(i);
    }
}
int main()
{   ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    string  s;
    cin>>t;

    while(t--)
    {

        cin>>n>>k>>s;
       if(n%k!=0){cout<<-1<<endl;continue;}
        for(int i=0;i<29;i++)fr[i]=0;
    for(int i=0;i<s.size();i++){fr[s[i]-'a']++;fr[s[i]-'a']%=k;}
    need=0;
    for(int i=0;i<26;i++)need+=(k-fr[i])%k;
    if(need==0){cout<<s<<endl;continue;}
    int r=-1;
    for(int i=s.size()-1;i>=0;i--)
    {
    while(s[i]!='z')
    {

    rem(s[i]-'a');
    s[i]++;
    add(s[i]-'a');
    if(need<s.size()-i){r=i;break;}
    }

    if(r!=-1)break;
    rem(s[i]-'a');

    }
    for(int i=0;i<=r;i++)cout<<s[i];
    for(int i=0;i<n-r-1-need;i++)cout<<'a';
    go();
    cout<<endl;
    }
    return 0;
}