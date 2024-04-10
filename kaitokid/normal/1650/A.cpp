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
        char c;
        cin>>s>>c;
        bool ans=false;
        for(int i=0;i<s.size();i+=2)if(s[i]==c)ans=true;
        if(ans)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
    }
    return 0;
}