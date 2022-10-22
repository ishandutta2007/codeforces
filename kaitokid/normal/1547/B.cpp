#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int wh[30];
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
    for(int i=0;i<28;i++)wh[i]=-1;
    for(int i=0;i<s.size();i++)wh[s[i]-'a']=i;
    if(wh[0]==-1){cout<<"NO\n";continue;}
    int l=wh[0],r=wh[0];
    bool ans=true;
    for(int i=1;i<s.size();i++)
    {
        if(wh[i]==-1){ans=false;break;}
        if(wh[i]== l-1){l--;continue;}
        if(wh[i]== r+1){r++;continue;}
        ans=false;
        break;
    }
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";
}
    return 0;
}