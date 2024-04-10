#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string rr(string x,string y)
{
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    string res="";
    for(int i=0;i<y.size();i++)
        if(x[i]=='1'||y[i]=='1')res+='1';else res+='0';
    for(int i=y.size();i<x.size();i++)res+=x[i];
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans=s,t=s;
    for(int i=0;i<min(50,n-1);i++)
    {
        t.pop_back();
        ans=max(ans,rr(s,t));
    }
    int i=0;
    while(i<n&&(ans[i]=='0'))i++;
    if(i==n){cout<<0;return 0;}
    for(int j=i;j<n;j++)cout<<ans[j];


    return 0;
}