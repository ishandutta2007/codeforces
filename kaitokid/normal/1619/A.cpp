#include <bits/stdc++.h>
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
        string s;
        cin>>s;
        int u=s.size();
        if(u%2){cout<<"NO"<<endl;continue;}
    u/=2;
    bool bl=true;
    for(int i=0;i<u;i++)
        if(s[i]!=s[i+u])bl=false;
    if(bl)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }

    return 0;
}