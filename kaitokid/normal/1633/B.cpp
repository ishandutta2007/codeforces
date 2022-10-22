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
        int u=0,v=0;
        for(int i=0;i<s.size();i++)if(s[i]=='0')u++;else v++;
        if(u==v)u--;
        cout<<min(u,v)<<endl;
    }
    return 0;
}