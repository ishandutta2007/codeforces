#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int t=0,ans=0,cot=0;
    for(int i=0;i<s.size();i++)
        if(s[i]=='G') cot++;
    for(int i=0;i<s.size();i++)
        if(s[i]=='G') t++;
    else
    {
        ans=max(ans,t);
        if(cot-t) ans=max(ans,t+1);
        if(i-t-2&&s[i-t-2]=='G') ans=max(ans,min(1+t+v[v.size()-1],cot));
        v.push_back(t);
        t=0;
    }
    ans=max(ans,t);
    if(t&&cot-t) ans=max(ans,t+1);
    if(t&&s.size()-t-2&&s[s.size()-t-2]=='G') ans=max(ans,min(1+t+v[v.size()-1],cot));
    cout<<ans<<endl;
}