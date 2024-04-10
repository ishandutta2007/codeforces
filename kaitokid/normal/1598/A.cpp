#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[2];
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>s[0]>>s[1];
        bool ans=true;
        for(int i=0;i<n;i++)
            if(s[0][i]=='1' && s[1][i]=='1')ans=false;
            if(ans)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
    }
    return 0;
}