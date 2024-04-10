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
        int u=0;
        for(int i=0;i<s.size();i++)
            if(s[i]=='N')u++;
        if(u==1)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
    }
    return 0;
}