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
       int n;
       cin>>n>>s;
    int ans=0,rem=s.size(), i=0;
    while(i+1<s.size())
    {
        if(s[i]=='('){rem-=2;ans++;i+=2;continue;}
        int j=i+1;
        while(j<n){if(s[j]==')')break;j++;}
        if(j==n)break;
        ans++;
        rem-=j-i+1;
        i=j+1;
    }
    cout<<ans<<" "<<rem<<endl;
    }
}