#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[5];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s[0]>>s[1]>>s[2]>>s[3];
        int u=max(s[0],s[1]);
        int v=max(s[2],s[3]);
        if(u<v)swap(u,v);
        sort(s,s+4);
        if((u==s[3])&&(v==s[2]))
            cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}