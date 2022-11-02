#include<bits/stdc++.h>
using namespace std;
int licz[105];
bool check()
{
    bool czy=true;
    for(int x=0;x<50;x++)
        if(licz[x]!=0)
            czy=false;
    return czy;
}
void solve()
{
    string a,b;
    cin>>a>>b;
    if(b.size()<a.size())
    {
        cout<<"NO"<<'\n';
        return ;
    }
    for(auto x:a)
        licz[x-'a']++;
    for(int x=0;x<a.size();x++)
        licz[b[x]-'a']--;
    bool czy=false;
    if(check()==true)
        czy=true;
    for(int x=a.size();x<b.size();x++)
    {
        licz[b[x-a.size()]-'a']++;
        licz[b[x]-'a']--;
        if(check()==true)
            czy=true;
    }
    if(czy==true)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<'\n';
    for(int x=0;x<=100;x++)
        licz[x]=0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}