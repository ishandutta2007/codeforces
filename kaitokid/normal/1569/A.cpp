#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=-1;
    for(int i=0;i+1<s.size();i++)
        if(s[i]!=s[i+1])ans=i+1;
    if(ans==-1){cout<<-1<<" "<<-1<<endl;}
    else cout<<ans<<" "<<ans+1<<endl;
}

    return 0;
}